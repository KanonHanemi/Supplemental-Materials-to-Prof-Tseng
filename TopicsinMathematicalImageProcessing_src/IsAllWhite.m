function k = IsAllWhite(im, x_pixel, y_pixel, target_sample)

n1 = floor((size(target_sample,1)-1)/2);
n2 = ceil((size(target_sample,1)-1)/2);
m1 = floor((size(target_sample,2)-1)/2);
m2 = ceil((size(target_sample,2)-1)/2);
cut_image = im(y_pixel-n1:y_pixel+n2, x_pixel-m1:x_pixel+m2);
cut_image = 1-cut_image/255;

if sum(cut_image,"all") <= 10
    k = 1;
else
    k = 0;
end


end