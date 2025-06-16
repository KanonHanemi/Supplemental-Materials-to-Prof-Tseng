% This function return the result of Judgement
% The return value is an integer 0 or 1
% 0 means that there is no target matched
%
% Author: Wei-Chih Chen

function result = SampleComparison(im, x_pixel, y_pixel, target_sample, judgement_rate)

n1 = floor((size(target_sample,1)-1)/2);
n2 = ceil((size(target_sample,1)-1)/2);
m1 = floor((size(target_sample,2)-1)/2);
m2 = ceil((size(target_sample,2)-1)/2);
%total_pix = size(target_sample,1)*size(target_sample,2);

cover = 0;
target_colored = 0;
cut_image = im(y_pixel-n1:y_pixel+n2, x_pixel-m1:x_pixel+m2);

for y = 1:size(target_sample,1)
    for x = 1:size(target_sample,2)
        if cut_image(y,x) == 0 && target_sample(y,x) == 0
            
            cover = cover + 1;
        end
        if target_sample(y,x) ~= 255
            target_colored = target_colored + 1;
        end
    end
end

cover_rate = cover / target_colored;
if cover_rate >= judgement_rate
    result = 1;
else
    result = 0;
end

end