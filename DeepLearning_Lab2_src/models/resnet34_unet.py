import torch
import torch.nn as nn
import torch.nn.functional as F
from torchvision import models

class Convolution(nn.Module):
    def __init__(self, in_channel, out_channel):
        super(Convolution, self).__init__()
        self.convolution = nn.Sequential(
            nn.Conv2d(in_channel + out_channel, out_channel, kernel_size=3, padding=1),
            nn.BatchNorm2d(out_channel),
            nn.ReLU(),
        )
        
    def forward(self, x):
        return self.convolution(x)


class ResBlock(nn.Module):
    def __init__(self, in_channel, out_channel, stride=1, downsample=None):
        super(ResBlock, self).__init__()
        self.conv1 = nn.Conv2d(in_channel, out_channel, kernel_size=3, stride=stride, padding=1, bias=False)
        self.batchnorm1 = nn.BatchNorm2d(out_channel)
        self.relu1 = nn.ReLU(inplace=True)
        
        self.conv2 = nn.Conv2d(out_channel, out_channel, kernel_size=3, stride=1, padding=1, bias=False)
        self.batchnorm2 = nn.BatchNorm2d(out_channel)
        
        self.stride = stride
        self.downsample = downsample
    
    def forward(self, x):
        out = self.conv1(x)
        out = self.batchnorm1(out)
        out = self.relu1(out)

        out = self.conv2(out)
        out = self.batchnorm2(out)
        
        if self.downsample is not None:
            x = self.downsample(x)
            
        out = out + x
        out = self.relu1(out)
        return out
    
'''    
class Layer(nn.Module):
    def __init__(self, in_channel, out_channel, block, stride=1):
        downsample = None
        if (stride != 1) or (in_channel != out_channel):
            downsample = nn.Sequential(
                nn.Conv2d(in_channel, out_channel, kernel_size=1, stride=stride, bias=False),
                nn.BatchNorm2d(out_channel),
            )
        self.layers = []
        self.layers.append(ResBlock(in_channel, out_channel, stride, downsample))
        for i in range(1, block):
            self.layers.append(ResBlock(out_channel, out_channel))
        
            
    def forward(self, x):
        return nn.Sequential(*self.layers)
'''        
        
            
class ResNet34(nn.Module):
    def __init__(self):
        super(ResNet34, self).__init__()
        
        # initial convolution
        self.conv1 = nn.Conv2d(1, 64, kernel_size=7, stride=2, padding=3, bias=False)
        self.batchnorm1 = nn.BatchNorm2d(64)
        self.relu1 = nn.ReLU(inplace=True)
        self.pool = nn.MaxPool2d(kernel_size=3, stride=2, padding=1)
        
        self.layer1 = self.Layer(64, 64, 3)
        self.layer2 = self.Layer(64, 128, 4, stride=2)
        self.layer3 = self.Layer(128, 256, 6, stride=2)
        self.layer4 = self.Layer(256, 512, 3, stride=2)
        
    def Layer(self, in_channel, out_channel, block, stride=1):
        downsample = None
        if (stride != 1) or (in_channel != out_channel):
            downsample = nn.Sequential(
                nn.Conv2d(in_channel, out_channel, kernel_size=1, stride=stride, bias=False),
                nn.BatchNorm2d(out_channel),
            )
        layers = []
        layers.append(ResBlock(in_channel, out_channel, stride, downsample))
        for i in range(1, block):
            layers.append(ResBlock(out_channel, out_channel))
            
        return nn.Sequential(*layers)
        
        
    def forward(self, x):
        x = self.conv1(x)
        x = self.batchnorm1(x)
        x = self.relu1(x)
        x = self.pool(x)

        layer1 = self.layer1(x)  # 64x64
        layer2 = self.layer2(layer1)  # 128x32
        layer3 = self.layer3(layer2)  # 256x16
        layer4 = self.layer4(layer3)  # 512x8

        return layer1, layer2, layer3, layer4
        

class ResNet34_UNet(nn.Module):
    def __init__(self):
        super(ResNet34_UNet, self).__init__()
        
        # Res34 Encoder
        self.res34 = ResNet34()
        
        # Unet Decoder
        self.up1 = Convolution(512, 256)
        self.up2 = Convolution(256, 128)
        self.up3 = Convolution(128, 64)
        self.up4 = nn.Sequential(
            nn.Conv2d(64, 32, kernel_size=3, padding=1),
            nn.BatchNorm2d(32),
            nn.ReLU(),
        )
        self.final_conv = nn.Conv2d(32, 1, kernel_size=1)
        
    def forward(self, x):
        # Res34
        layer1, layer2, layer3, layer4 = self.res34(x)
        
        # Unet
        x = F.interpolate(layer4, size=layer3.shape[2:], mode='bilinear', align_corners=False)
        x = self.up1(torch.cat([x, layer3], dim=1))
        
        x = F.interpolate(x, size=layer2.shape[2:], mode='bilinear', align_corners=False)
        x = self.up2(torch.cat([x, layer2], dim=1))
        
        x = F.interpolate(x, size=layer1.shape[2:], mode='bilinear', align_corners=False)
        x = self.up3(torch.cat([x, layer1], dim=1))
        
        x = F.interpolate(x, scale_factor=2, mode='bilinear', align_corners=False)
        x = self.up4(x)
        
        x = self.final_conv(x)
        x = F.interpolate(x, size=(256, 256), mode='bilinear', align_corners=False)
        x = torch.sigmoid(x)
        x = torch.round(x)
        return x
        
# assert False, "Not implemented yet!"        
