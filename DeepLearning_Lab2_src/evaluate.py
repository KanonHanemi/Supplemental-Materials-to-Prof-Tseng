def evaluate(net, data, device):
    import torch
    import torch.utils.checkpoint as checkpoint
    from utils import CalculateDiceScore
    from models.unet import UNet
    from models.resnet34_unet import ResNet34_UNet

    if net == "unet":
        model = UNet()
        model.load_state_dict(torch.load("../saved_models/unet.pth", map_location=device))
        model.to(device)
    elif net == "res34unet":
        model = ResNet34_UNet()
        model.load_state_dict(torch.load("../saved_models/res34unet.pth", map_location=device))
        model.to(device)

    model.eval()
    total_dice = 0.0
    total_samples = 0

    print(f"evaluation:")
    with torch.no_grad():
        idx = 0
        for batch in data:
            images = batch["image"].to(device)
            masks = batch["mask"].to(device)

            # ensure the image is a 4D tensor（batch_size, channels, height, width）
            if images.dim() == 3:  # is 3D tensor（channels, height, width）
                images = images.unsqueeze(0)  # add batch_size dimension

            pred = checkpoint.checkpoint(model, images)

            dice = CalculateDiceScore(pred, masks)
            if (idx % 50 == 0):
                print(f"model: {net}, index: {idx} dice score : {dice}")
            total_dice = total_dice + dice
            total_samples += 1
            idx += 1

    avg_dice = total_dice / total_samples
    
    return avg_dice
