# Implement your UNet model here
import torch
import torch.nn as nn
import torch.nn.functional as F

class DoubleConv(nn.Module):
    def __init__(self, in_channel, out_channel):
        super(DoubleConv, self).__init__()
        self.double_conv = nn.Sequential(
            nn.Conv2d(in_channel, out_channel, kernel_size=3, padding=1),
            nn.BatchNorm2d(out_channel),
            nn.ReLU(),
            
            nn.Conv2d(out_channel, out_channel, kernel_size=3, padding=1),
            nn.BatchNorm2d(out_channel),
            nn.ReLU()
        )
        
    def forward(self, x):
        return self.double_conv(x)
    
class Upward(nn.Module):
    def __init__(self, in_channel, out_channel):
        super(Upward, self).__init__()
        self.up_ward = nn.Sequential(
            nn.Upsample(scale_factor=2, mode='bilinear', align_corners=True),
            nn.Conv2d(in_channel, out_channel, kernel_size=3, padding=1),
        )
    
    def forward(self, x):
        return self.up_ward(x)


class UNet(nn.Module):
    def __init__(self):
        super(UNet, self).__init__()
        
        self.down1 = DoubleConv(1,64)
        self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        self.down2 = DoubleConv(64,128)
        self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        self.down3 = DoubleConv(128,256)
        self.pool3 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        self.down4 = DoubleConv(256,512)
        self.pool4 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        self.middle = DoubleConv(512,1024)
        
        self.up1 = Upward(1024,512)
        self.up_conv1 = DoubleConv(1024,512)
        
        self.up2 = Upward(512,256)
        self.up_conv2 = DoubleConv(512,256)
        
        self.up3 = Upward(256,128)
        self.up_conv3 = DoubleConv(256,128)
        
        self.up4 = Upward(128,64)
        self.up_conv4 = DoubleConv(128,64)
        
        self.final_conv = nn.Conv2d(64, 1, kernel_size=1)
        
    # def DoubleConv(self, in_channel, out_channel):
    #     conv = nn.Sequential(
    #     nn.Conv2d(in_channel, out_channel, kernel_size=3, padding=1),
    #     nn.BatchNorm2d(out_channel),
    #     nn.ReLU(),
        
    #     nn.Conv2d(out_channel, out_channel, kernel_size=3, padding=1),
    #     nn.BatchNorm2d(out_channel),
    #     nn.ReLU()
    #     )
    #     return conv
    
    # def Upward(self, in_channel, out_channel):
    #     up_ward = nn.Sequential(
    #         nn.Upsample(scale_factor=2, mode='bilinear', align_corners=True),
    #         nn.Conv2d(in_channel, out_channel, kernel_size=3, padding=1),
    #     )
    #     return up_ward
        
    def forward(self, x):
        encoder1 = self.down1(x)
        max_pool1 = self.pool1(encoder1)
        
        encoder2 = self.down2(max_pool1)
        max_pool2 = self.pool2(encoder2)
        
        encoder3 = self.down3(max_pool2)
        max_pool3 = self.pool3(encoder3)
        
        encoder4 = self.down4(max_pool3)
        max_pool4 = self.pool4(encoder4)
        
        middle_layer = self.middle(max_pool4)
        
        upward1 = self.up1(middle_layer)
        upward1 = F.interpolate(upward1, size=encoder4.shape[2:], mode="bilinear", align_corners=True)
        decoder1 = self.up_conv1(torch.cat([upward1, encoder4], dim=1))
        
        upward2 = self.up2(decoder1)
        upward2 = F.interpolate(upward2, size=encoder3.shape[2:], mode="bilinear", align_corners=True)
        decoder2 = self.up_conv2(torch.cat([upward2, encoder3], dim=1))
        
        upward3 = self.up3(decoder2)
        upward3 = F.interpolate(upward3, size=encoder2.shape[2:], mode="bilinear", align_corners=True)
        decoder3 = self.up_conv3(torch.cat([upward3, encoder2], dim=1))
        
        upward4 = self.up4(decoder3)
        upward4 = F.interpolate(upward4, size=encoder1.shape[2:], mode="bilinear", align_corners=True)
        decoder4 = self.up_conv4(torch.cat([upward4, encoder1], dim=1))
        
        out = self.final_conv(decoder4)
        out = torch.sigmoid(out)
        out = torch.round(out)
        out = out
        return out
    
