% This is the first process that filter the specified RGB color out
% The parameter "filename" and "color" is necessary
% The parameter "filename" should be the name consist with image format
% The parameter "color" should only be "red", "green" or "blue",
%     the color parameter determines which color should filter out.
% The parameter "layer" is optional, it should only be "R","G" or "B",
%     the layer parameter determines which layer should be returned
% If the "layer" parameter is included, this filter will return a
%     matrix that only show the layer
% If not, this filter will return an m*n*3 tensor, which is 
%     the format of an RGB image
%
% Author: Wei-Chih Chen

function im = ColorFilter(filename, color, layer)

im = imread(filename);

if size(im,3) == 3
    if color == "red"
        for i = 1:size(im,1)
            for j = 1:size(im,2)
                if im(i,j,1) >= 80 && im(i,j,2) <= 100 && im(i,j,3) <= 100
                    im(i,j,1) = 255;
                    im(i,j,2) = 0;
                    im(i,j,3) = 0;
                else
                    im(i,j,1) = 255;
                    im(i,j,2) = 255;
                    im(i,j,3) = 255;
                end
            end
        end
    elseif color == "green"
        for i = 1:size(im,1)
            for j = 1:size(im,2)
                if im(i,j,2) >= 80 && im(i,j,1) <= 100 && im(i,j,3) <= 100
                    im(i,j,1) = 0;
                    im(i,j,2) = 255;
                    im(i,j,3) = 0;
                else
                    im(i,j,1) = 255;
                    im(i,j,2) = 255;
                    im(i,j,3) = 255;
                end
            end
        end
    elseif color == "blue"
        for i = 1:size(im,1)
            for j = 1:size(im,2)
                if im(i,j,3) >= 80 && im(i,j,1) <= 100 && im(i,j,2) <= 100
                    im(i,j,1) = 0;
                    im(i,j,2) = 0;
                    im(i,j,3) = 255;
                else
                    im(i,j,1) = 255;
                    im(i,j,2) = 255;
                    im(i,j,3) = 255;
                end
            end
        end
    end

if exist("layer","var")
    if layer == "R"
        im = im(:,:,1);
    elseif layer == "G"
        im = im(:,:,2);
    elseif layer == "B"
        im = im(:,:,3);
    end
end

end