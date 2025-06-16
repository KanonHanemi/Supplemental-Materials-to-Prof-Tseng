def CalculateDiceScore(pred_mask, gt_mask):
    import torch
    pred_mask = torch.round(pred_mask.float())
    gt_mask = torch.round(gt_mask.float())

    common_pixels = torch.sum((pred_mask * gt_mask) > 0.5) + torch.sum(((1-pred_mask) * (1-gt_mask)) > 0.5)
    pred_size = torch.sum(pred_mask) + torch.sum(1-pred_mask)
    gt_size = torch.sum(gt_mask) + torch.sum(1-gt_mask)
    
    return 2 * common_pixels / (pred_size + gt_size)


def LossFunction(pred_mask, gt_mask):
    import torch
    pred_mask = torch.round(pred_mask)
    
    return 1 - CalculateDiceScore(pred_mask, gt_mask)


def DetectEdges(image):
    import cv2
    # 使用 Canny 檢測邊界
    edges = cv2.Canny(image, 50, 100)

    # 將邊界圖像轉換為黑白圖像
    binary_edges = (edges > 0).astype('uint8') * 255  # 邊界為白色（255），背景為黑色（0）
    return binary_edges
