clear;clc;

% Author: Wei-Chih Chen
% The whole project was done without using any AI tools
% Only specified image will work
% This is the version that can check the mid parameter
%
% Kindly open the "dialogue" variable to see the details
% Change the 3rd parameter of the "dialogue" tensor to see
%     the cover rate through different symbols
% Note that the rows and the columns corresponds to the
%     detection point on the original chart
% The meaning of 3rd parameter of the "dialogue" is:
%     1-cross   2-square    3-large  4-right_square
%     5-circle  6-triangle  7-small  8-left_square
% 9 to 16 is the same as above but there is an arrow on it
%
% Enter your image name with .jpg file extension below
% Note that try to use the relative path
% There may cause some unpredictable error if the
%     file name used the absolute path 

image_name = "20190627_104544_000053339B_.jpg";

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
frequency = [250 500 750 1000 1500 2000 3000 4000 6000 8000];
decibel = [-5; 0; 5; 10; 15; 20; 25; 30; 35; 40; 45; 50; 55; 60;
      65; 70; 75; 80; 85; 90; 95; 100; 105; 110; 115; 120];

dialogue = zeros(26,10,16);
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
            final_blue_arrow_result = 0;
            for x_addition = -4:1:4
                for y_addition = -4:1:4
                    white_blue = IsAllWhite(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number});
                    white_red = IsAllWhite(red_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number});
                    if (white_blue + white_red) == 2
                        break;
                    end
                    blue_result = SampleComparison2(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape{shape_number});
                    blue_arrow_result = SampleComparison2(blue_im,x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, blue_shape_arrow{shape_number});
                    if blue_result > final_blue_result
                        final_blue_result = blue_result;
                    end
                    if blue_arrow_result > final_blue_arrow_result
                        final_blue_arrow_result = blue_arrow_result;
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
            
            if (final_blue_arrow_result >= 0.85) || (final_blue_result >= 0.85)
                blue_detected = 1;
            end
            dialogue(dB,freq,shape_number) = final_blue_result;
            dialogue(dB,freq,8+shape_number) = final_blue_arrow_result;
        end

        for shape_number = 1:size(red_shape,2)
            final_red_result = 0;
            final_red_arrow_result = 0;
            for x_addition = -4:1:4
                for y_addition = -4:1:4
                    red_result = SampleComparison2(red_im, x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, red_shape{shape_number});
                    red_arrow_result = SampleComparison2(red_im, x_cor(freq)+x_addition, ...
                        y_cor(dB)+y_addition, red_shape_arrow{shape_number});
                    if red_result > final_red_result
                        final_red_result = red_result;
                    end
                    if red_arrow_result > final_red_arrow_result
                        final_red_arrow_result = red_arrow_result;
                    end
                end
            end
            if (final_red_result >= 0.85) || (final_red_arrow_result >= 0.85)
                red_detected = 1;
            end
            dialogue(dB,freq,4+shape_number) = final_red_result;
            dialogue(dB,freq,12+shape_number) = final_red_arrow_result;
        end
        
        if blue_detected >= 1 %blue complete shape detected
            for shape_number = 1:size(blue_shape_half,2)
                final_blue_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        blue_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number});
                        blue_arrow_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number});
                        if blue_result > final_blue_result
                        final_blue_result = blue_result;
                        end
                        if blue_arrow_result > final_blue_arrow_result
                            final_blue_arrow_result = blue_arrow_result;
                        end
                    end
                end
                if (final_blue_arrow_result >= 0.85) || (final_blue_result >= 0.85)
                blue_detected = 1;
                end
                dialogue(dB,freq,2+shape_number) = final_blue_result;
                dialogue(dB,freq,10+shape_number) = final_blue_arrow_result;

                final_red_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        red_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number});
                        red_arrow_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number});
                        if red_result > final_red_result
                        final_red_result = red_result;
                        end
                        if red_arrow_result > final_red_arrow_result
                            final_red_arrow_result = red_arrow_result;
                        end
                    end
                end
                if (final_red_result >= 0.85) || (final_red_arrow_result >= 0.85)
                red_detected = 1;
                end
                dialogue(dB,freq,6+shape_number) = final_red_result;
                dialogue(dB,freq,14+shape_number) = final_red_arrow_result;
            end
            
            
        elseif red_detected >= 1 %red complete shape detected
            for shape_number = 1:size(blue_shape_half,2)
                final_blue_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        blue_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number});
                        blue_arrow_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number});
                        if blue_result > final_blue_result
                        final_blue_result = blue_result;
                        end
                        if blue_arrow_result > final_blue_arrow_result
                            final_blue_arrow_result = blue_arrow_result;
                        end
                    end
                end
                if (final_blue_arrow_result >= 0.85) || (final_blue_result >= 0.85)
                blue_detected = 1;
                end
                dialogue(dB,freq,2+shape_number) = final_blue_result;
                dialogue(dB,freq,10+shape_number) = final_blue_arrow_result;

                final_red_result = 0;
                for x_addition = 28:1:43
                    for y_addition = -4:1:4
                        red_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number});
                        red_arrow_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number});
                        if red_result > final_red_result
                        final_red_result = red_result;
                        end
                        if red_arrow_result > final_red_arrow_result
                            final_red_arrow_result = red_arrow_result;
                        end
                    end
                end
                if (final_red_result >= 0.85) || (final_red_arrow_result >= 0.85)
                red_detected = 1;
                end
                dialogue(dB,freq,6+shape_number) = final_red_result;
                dialogue(dB,freq,14+shape_number) = final_red_arrow_result;
            end

        else %no complete shape detected
            for shape_number = 1:size(blue_shape_half,2)
                final_blue_result = 0;
                for x_addition = 3:1:18
                    for y_addition = -4:1:4
                        blue_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_half{shape_number});
                        blue_arrow_result = SampleComparison2(blue_im, x_cor(freq)+x_addition, ...
                            y_cor(dB)+y_addition, blue_shape_arrow_half{shape_number});
                        if blue_result > final_blue_result
                        final_blue_result = blue_result;
                        end
                        if blue_arrow_result > final_blue_arrow_result
                            final_blue_arrow_result = blue_arrow_result;
                        end
                    end
                end
                if (final_blue_arrow_result >= 0.85) || (final_blue_result >= 0.85)
                blue_detected = 1;
                end
                dialogue(dB,freq,2+shape_number) = final_blue_result;
                dialogue(dB,freq,10+shape_number) = final_blue_arrow_result;

                final_red_result = 0;
                for x_addition = 3:1:18
                    for y_addition = -4:1:4
                        red_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_half{shape_number});
                        red_arrow_result = SampleComparison2(red_im,x_cor(freq)-x_addition, ...
                            y_cor(dB)+y_addition, red_shape_arrow_half{shape_number});
                        if red_result > final_red_result
                        final_red_result = red_result;
                        end
                        if red_arrow_result > final_red_arrow_result
                            final_red_arrow_result = red_arrow_result;
                        end
                    end
                end
                if (final_red_result >= 0.85) || (final_red_arrow_result >= 0.85)
                red_detected = 1;
                end
                dialogue(dB,freq,6+shape_number) = final_red_result;
                dialogue(dB,freq,14+shape_number) = final_red_arrow_result;
            end
        end

    end %for db
end %for freq

%elapsed time 33.142877 sec. with no white break
%elapsed time 25.385459 sec. with white break


fprintf("Detection Completed, please open the 'dialogue' variable at the workspace to check the details.");
