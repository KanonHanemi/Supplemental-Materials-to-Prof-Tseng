import argparse

def test(args):
    from oxford_pet import load_dataset
    from torch.utils.data import DataLoader
    import torch
    from models.unet import UNet
    from models.resnet34_unet import ResNet34_UNet 
    from utils import CalculateDiceScore
    import torch.utils.checkpoint as checkpoint
    
    data = load_dataset(args.data_path, "test")
    
    if torch.cuda.is_available():
        device = torch.device("cuda")
    else:
        device = torch.device("cpu")
    print(f"Testing on device: {device}")
        
    if (args.model_type == "unet"):
        model = UNet().to(device)
        model.load_state_dict(torch.load(args.model, weights_only=True))
    elif (args.model_type == "res34unet"):
        model = ResNet34_UNet().to(device)
        model.load_state_dict(torch.load(args.model, weights_only=True))
    print(f"Current model: {model}")

    model.eval()
    total_dice = 0.0
    dice_list = []
    test_loader = DataLoader(data, args.batch_size, shuffle= False)
    for batch_idx, batch in enumerate(test_loader):
        
            image = batch["image"].to(device, dtype=torch.float32)
            mask = batch["mask"].to(device)

            # pred = model(image)
            pred = checkpoint.checkpoint(model, image)
            dice_score = CalculateDiceScore(pred, mask)/args.batch_size
            total_dice = total_dice + dice_score
            dice_list.append(dice_score)
            print(f"batch: {batch_idx} dic: {dice_score:.5f}")

    avg_dice = total_dice/(len(dice_list)+1)
    print(f"dice score: {avg_dice:.4f}")

    return avg_dice


def get_args():
    parser = argparse.ArgumentParser(description='Predict masks from input images')
    parser.add_argument('--model', default='MODEL.pth', help='path to the stored model weoght')
    parser.add_argument('--data_path', type=str, help='path to the input data', default="../dataset/oxford-iiit-pet")
    parser.add_argument('--batch_size', '-b', type=int, default=2, help='batch size')
    parser.add_argument('--model_type', type=str)
    return parser.parse_args()

if __name__ == '__main__':
    args = get_args()
    args.model = "../saved_models/unet.pth"
    args.model_type = "unet"
    unet_score = test(args)
    
    args.model = "../saved_models/res34unet.pth"
    args.model_type = "res34unet"
    res_score = test(args)
    
    print(f"UNet score: {unet_score:.5f}")
    print(f"ResNet34 score: {res_score:.5f}")