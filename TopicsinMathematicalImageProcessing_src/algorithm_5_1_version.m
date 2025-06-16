clear;clc;

% Author: Wei-Chih Chen
% The whole project was done without using any AI tools
% Only specified image will work
% This is the version that only outputs a file that 
%
% Enter your image name with .jpg file extension below
% For the output file, enter the file name with file extension
% such as myfile.xlsx or any format that Matlab support
% Format that supported: .txt .dat .csv .xls .xlsm .xlsx .xlsb .xml
% Note that try to use the relative path
% The .xlsx format is recommended

image_name = "20190703_093821_001224109H_.jpg";
output_filename_with_format = "20190703_093821_001224109H_.xlsx";

%%%%%%%%%%% TRY TO AVOID ANY MODIFICATION BELOW %%%%%%%%%%%

red_im = ColorFilter(image_name,"red","G");
blue_im = ColorFilter(image_name,"blue","G");

%Sample area
circle_sample_01 = ColorFilter("circle_sample_1.jpg","red","G");
triangle_sample_01 = ColorFilter("tri_sample_1.jpg","red","G");
x_sample_01 = ColorFilter("x_sample_1.jpg","blue","G");
square_sample_01 = ColorFilter("square_sample_1.jpg","blue","G");
small_sample_01 = ColorFilter("small.jpg","red","G");
leftsquare_sample = ColorFilter("leftsquare.jpg","red","G");
large_sample_01 = ColorFilter("large.jpg","blue","G");
rightsquare_sample = ColorFilter("rightsquare.jpg","blue","G");

%with arrow
circle_arrow = ColorFilter("circle_arrow.jpg","red","G");
triangle_arrow = ColorFilter("triangle_arrow.jpg","red","G");
small_arrow = ColorFilter("small_arrow.jpg","red","G");
leftsquare_arrow = ColorFilter("leftsquare_arrow.jpg","red","G");
square_arrow = ColorFilter("square_arrow.jpg","blue","G");
x_arrow = ColorFilter("x_arrow.jpg","blue","G");
large_arrow = ColorFilter("large_arrow.jpg","blue","G");
rightsquare_arrow = ColorFilter("rightsquare_arrow.jpg","blue","G");

red_shape{1} = circle_sample_01;
red_shape{2} = triangle_sample_01;
red_shape_half{1} = small_sample_01;
red_shape_half{2} = leftsquare_sample;
blue_shape{1} = x_sample_01;
blue_shape{2} = square_sample_01;
blue_shape_half{1} = large_sample_01;
blue_shape_half{2} = rightsquare_sample;
red_shape_arrow{1} = circle_arrow;
red_shape_arrow{2} = triangle_arrow;
red_shape_arrow_half{1} = small_arrow;
red_shape_arrow_half{2} = leftsquare_arrow;
blue_shape_arrow{1} = x_arrow;
blue_shape_arrow{2} = square_arrow;
blue_shape_arrow_half{1} = large_arrow;
blue_shape_arrow_half{2} = rightsquare_arrow;
%Sample area end


x_cor = [508 647 731 790 872 928 1012 1071 1150 1209];
y_cor = [593; 631; 670; 708; 746; 784; 822; 860; 898; 936; 974; 1012; 1050;
      1088; 1126; 1164; 1202; 1240; 1278; 1312; 1354; 1392; 1430; 1468; 1506; 1544];

% x_cor = [525 673 759 822 907 971 1060 1121 1208 1268];
% y_cor = [639; 678; 719; 760; 699; 838; 877; 916; 955; 994; 1033; 1072; 1111;
%       1150; 1189; 1228; 1267; 1306; 1345; 1384; 1423; 1462; 1501; 1540; 1579; 1618];

decibel = [-5; 0; 5; 10; 15; 20; 25; 30; 35; 40; 45; 50; 55; 60;
      65; 70; 75; 80; 85; 90; 95; 100; 105; 110; 115; 120];

shape_record = NaN(35,7);
point = 1;

for freq = 1:10
    %clc;
    fprintf("line %d of 10 is processing.\n",freq)
    for dB = 1:26
        fprintf("=")
        if dB == 26
            fprintf("\n");
        end
        %version 5
        red_detected = 0;
        blue_detected = 0;
        for shape_number = 1:size(blue_shape,2)
            final_blue_result = 0;
            
            for x_addition = -4:1:4
                for y_addition = -4:1:4
                    white_blue = IsAllWhite(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number});
                    white_red = IsAllWhite(red_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number});
                    if (white_blue + white_red) == 2
                        break;
                    end
                    blue_result = SampleComparison(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number}, 0.85);
                    blue_arrow_result = SampleComparison(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape_arrow{shape_number}, 0.90);
                    if blue_result == 1
                        final_blue_result = 1;
                    end
                    if blue_arrow_result == 1
                        final_blue_result = 2;
                        break;
                    end
                end
                if (white_blue + white_red) == 2
                    break;
                end
                if final_blue_result == 2
                    break;
                end
            end

            if (white_blue + white_red) == 2
                break;
            end
            
            if final_blue_result == 1
                blue_detected = 1;

                if shape_number == 1 %x
                    shape_record(point,:) = [point freq-1 0 decibel(dB) 1 0 0];
                elseif shape_number == 2 %square
                    shape_record(point,:) = [point freq-1 0 decibel(dB) 1 1 0];
                end

                point = point + 1;
            end
            if final_blue_result == 2
                blue_detected = 1;

                if shape_number == 1 %x
                    shape_record(point,:) = [point freq-1 0 decibel(dB) 1 0 1];
                elseif shape_number == 2 %square
                    shape_record(point,:) = [point freq-1 0 decibel(dB) 1 1 1];
                end
                point = point + 1;
            end
        end

        for shape_number = 1:size(red_shape,2)
            final_red_result = 0;
            if blue_detected == 1
                k = 0.70;
            else
                k = 0.85;
            end
            for x_addition = -4:1:4
                for y_addition = -4:1:4
                    red_result = SampleComparison(red_im, x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, red_shape{shape_number}, k);
                    red_arrow_result = SampleComparison(red_im, x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, red_shape_arrow{shape_number}, k+0.05);
                    if red_result == 1
                        final_red_result = 1;
                    end
                    if red_arrow_result == 1
                        final_red_result = 2;
                        break;
                    end
                end
                if final_red_result == 2
                    break;
                end
            end
            if final_red_result == 1
                red_detected = 1;
                if shape_number == 1 %circle
                    shape_record(point,:) = [point freq-1 1 decibel(dB) 1 0 0];
                elseif shape_number == 2 %triangle
                    shape_record(point,:) = [point freq-1 1 decibel(dB) 1 1 0];

                end
                point = point + 1;
            end
            if final_red_result == 2
                red_detected = 1;
                if shape_number == 1 %circle
                    shape_record(point,:) = [point freq-1 1 decibel(dB) 1 0 1];
                elseif shape_number == 2 %triangle
                    shape_record(point,:) = [point freq-1 1 decibel(dB) 1 1 1];
                end
                point = point + 1;
            end
        end
        
        if blue_detected >= 1 %blue complete shape detected
            for shape_number = 1:size(blue_shape_half,2)
                final_blue_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        blue_result = SampleComparison(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number}, 0.85);
                        blue_arrow_result = SampleComparison(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number}, 0.90);
                        if blue_result == 1
                            final_blue_result = 1;
                        end
                        if blue_arrow_result == 1
                            final_blue_result = 2;
                        end
                    end
                    if final_blue_result == 2
                        break;
                    end
                end
                if final_blue_result == 1
                    if shape_number == 1 %large
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %right square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_blue_result == 2
                    if shape_number == 1 %large
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %right square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end

                final_red_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        red_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number},0.85);
                        red_arrow_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number},0.90);
                        if red_result == 1
                            final_red_result = 1;
                        end
                        if red_arrow_result == 1
                            final_red_result = 2;
                            break;
                        end
                    end
                    if final_red_result == 2
                        break;
                    end
                end
                if final_red_result == 1
                    if shape_number == 1 %small
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %left square
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_red_result == 2
                    if shape_number == 1 %small
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %left square
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end
            end
            
            
        elseif red_detected >= 1 %red complete shape detected
            for shape_number = 1:size(red_shape_half,2)
                final_red_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        red_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number},0.85);
                        red_arrow_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number},0.90);
                        if red_result == 1
                            final_red_result = 1;
                        end
                        if red_arrow_result == 1
                            final_red_result = 2;
                            break;
                        end
                    end
                    if final_red_result == 2
                        break;
                    end
                end
                if final_red_result == 1
                    if shape_number == 1 %small
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %left square
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_red_result == 2
                    if shape_number == 1 %small
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %left square
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end

                final_blue_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        blue_result = SampleComparison(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number}, 0.85);
                        blue_arrow_result = SampleComparison(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number}, 0.90);
                        if blue_result == 1
                            final_blue_result = 1;
                        end
                        if blue_arrow_result == 1
                            final_blue_result = 2;
                        end
                    end
                    if final_blue_result == 2
                        break;
                    end
                end
                if final_blue_result == 1
                    if shape_number == 1 %large
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %right square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_blue_result == 2
                    if shape_number == 1 %large
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %right square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end
            end

        else %no complete shape detected
            for shape_number = 1:size(red_shape,2)
                final_blue_result = 0;
                
                for x_addition = 3:1:18
                    for y_addition = -4:1:4
                        blue_result = SampleComparison(blue_im,x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number},0.85);
                        blue_arrow_result = SampleComparison(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number}, 0.90);
                        if blue_result == 1
                            final_blue_result = 1;
                        end
                        if blue_arrow_result == 1
                            final_blue_result = 2;
                            break;
                        end
                    end
                    if final_blue_result == 2
                        break;
                    end
                end
                
                if final_blue_result == 1
                    if shape_number == 1 %x
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_blue_result == 2
                    if shape_number == 1 %x
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %square
                        shape_record(point,:) = [point freq-1 0 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end
            end

            for shape_number = 1:size(red_shape,2)
                final_red_result = 0;
                for x_addition = 3:1:18
                    for y_addition = -4:1:4
                        red_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number},0.85);
                        red_half_result = SampleComparison(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number},0.85);
                        if red_result == 1
                            final_red_result = 1;
                        end
                        if red_arrow_result == 1
                            final_red_result = 2;
                            break;
                        end
                    end
                    if final_red_result == 2
                        break;
                    end
                end
                
                if final_red_result == 1

                    if shape_number == 1 %circle
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 0];
                    elseif shape_number == 2 %triangle
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 0];
                    end
                    point = point + 1;
                end
                if final_red_result == 2
                    if shape_number == 1 %circle
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 0 1];
                    elseif shape_number == 2 %triangle
                        shape_record(point,:) = [point freq-1 1 decibel(dB) 0 1 1];
                    end
                    point = point + 1;
                end
            end
        end

    end %for db
end %for freq

%elapsed time 33.142877 sec. with no white break
%elapsed time 25.385459 sec. with white break

shape_record = rmmissing(shape_record);
TF = isempty(shape_record);
if TF
    fprintf("Detection Failed, try another figure");
else
    output = array2table(shape_record,"VariableNames",{'Point', 'Hz', 'Laterality', 'Level', 'Conduction', 'Masked', 'Overwhelm'});
    writetable(output,output_filename_with_format);
    fprintf("Detection Completed, please check the output file.");
end
