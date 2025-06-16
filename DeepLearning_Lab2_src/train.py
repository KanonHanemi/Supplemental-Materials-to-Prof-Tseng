import argparse

def train(args):
    # implement the training function here
    # 準備dataset
    from oxford_pet import load_dataset
    from torch.utils.data import DataLoader
    from torchvision import transforms
    from utils import CalculateDiceScore, LossFunction
    import torch
    import torch.optim as optim
    import torch.nn as nn
    from models.unet import UNet
    from models.resnet34_unet import ResNet34_UNet
    from torch.optim.lr_scheduler import StepLR
    import random
    import numpy as np
    from evaluate import evaluate
    
    seed = args.seed
    random.seed(seed) 
    np.random.seed(seed) 
    torch.manual_seed(seed) 
    torch.cuda.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    from torch.cuda.amp import autocast, GradScaler
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = True

    # device settings
    net = args.model
    if torch.cuda.is_available():
        device = torch.device("cuda")
    else:
        device = torch.device("cpu") 
    print(f"Training on device: {device}")

    # model settings
    if net == "unet":
        model = UNet().to(device)
    elif net == "res34unet":
        model = ResNet34_UNet().to(device)
    print(f"Current model: {net}")

    # dataset path settings
    data_path = args.data_path
    train_dataset = load_dataset(data_path, "train")
    valid_dataset = load_dataset(data_path, "valid")

    batch_size = args.batch_size
    train_loader = DataLoader(train_dataset , batch_size = batch_size , shuffle = False)

    optimizer = optim.Adam(model.parameters(), lr = args.learning_rate)
    scheduler = StepLR(optimizer, step_size=5, gamma=0.1)
    scaler = GradScaler() 
    
    for epoch in range(args.epochs):
        for batch_idx, batch in enumerate(train_loader):
            image = batch["image"]
            mask = batch["mask"]
            trimap = batch["trimap"]
            
            image = image.to(dtype=torch.float32, device=device)
            mask = mask.to(device)
            trimap = trimap.to(device)
            mask = mask.unsqueeze(1)

            optimizer.zero_grad()
            
            with autocast():  # 啟用混合精度
                pred = model(image)
                loss = LossFunction(pred, mask)

            scaler.scale(loss).backward()  # 梯度縮放
            scaler.step(optimizer)  # 梯度更新
            scaler.update()

            dic = CalculateDiceScore(pred, mask)

            print(f"epoch {epoch+1}, batch index: {batch_idx:4}({100*batch_idx / len(train_loader):.1f}%), {net} score: {dic.item():.4f} loss: {loss.item():.4f}")
        
        # log_file = f"./{net}_evaluate.txt"
        # log_msg = f"seed: {args.seed}, Avg dice score: {evaluate_score:4f}\n"
        # with open(log_file, "a") as f:
        #     f.write(log_msg)
            
        # print(f"{net} Average dice score: {evaluate_score:4f}")
    
    # Train finished
    torch.save(model.state_dict(), f"../saved_models/{net}.pth")
    evaluate_score = evaluate(net, valid_dataset, device)
    print(f"{net} Average dice score: {evaluate_score:4f}")


def get_args():
    parser = argparse.ArgumentParser(description='Train the UNet on images and target masks')
    parser.add_argument('--data_path', type=str, help='path of the input data' ,default="../dataset/oxford-iiit-pet")
    parser.add_argument('--epochs', '-e', type=int, default=1, help='number of epochs')
    parser.add_argument('--batch_size', '-b', type=int, default=8, help='batch size') ## default = 1
    parser.add_argument('--learning-rate', '-lr', type=float, default=1e-4, help='learning rate')
    parser.add_argument('--model', type=str, choices=['unet', 'res34unet'], help='Choose the model: unet or resnet')
    parser.add_argument('--seed',type = int, default=1)
    return parser.parse_args()
 
if __name__ == "__main__":
    args = get_args()

    # for seed in range(1000):
    #     args.seed = seed
    #     args.model = "unet"
    #     train(args)
    #     args.model = "res34unet"
    #     train(args)
        
    # args.seed = 166
    args.seed = 128
    args.model = "res34unet"
    train(args)

    args.seed = 166
    args.model = "unet"
    train(args)
    #1.08.77
    