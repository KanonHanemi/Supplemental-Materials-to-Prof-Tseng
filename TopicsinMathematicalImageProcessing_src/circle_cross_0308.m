clear;clc;

im = ColorFilter("10C.jpg","red");

%%%%%%%%%%training sample area

circle_sample_01 = ColorFilter("circle_sample_1.jpg","red","G");
triangle_sample_01 = ColorFilter("tri_sample_1.jpg","red","G");

%%%%%%%%%%training sample area


x_cor = [509 647 731 790 872 928 1012 1071 1150 1209];
y_cor = [593; 631; 669; 708; 746; 784; 822; 860; 898; 936; 974; 1012; 1050;
      1088; 1126; 1164; 1202; 1240; 1278; 1312; 1354; 1392; 1430; 1468; 1506; 1544];
freq = [250 500 750 1000 1500 2000 3000 4000 6000 8000];
db = [-5; 0; 5; 10; 15; 20; 25; 30; 35; 40; 45; 50; 55; 60;
      65; 70; 75; 80; 85; 90; 95; 100; 105; 110; 115; 120];

sheet = zeros(26,10,4);

sheet(:,:,1) = repmat(x_cor,26,1);
sheet(:,:,2) = repmat(y_cor,1,10);
sheet(:,:,3) = repmat(freq,26,1);
sheet(:,:,4) = repmat(db,1,10);

%circle detection start
%Image Process


G = im(:,:,2);
line = zeros(1,2);
for i = 450:1350
    for j = 480:1580
        if G(j,i) == 0
            line(i-449,1) = i;
            line(i-449,2) = j;
            break;
        end
        if j == 1580 && G(i,j) ~= 0
            line(i-449,1) = 0;
            line(i-449,2) = 0;
        end
    end
end

A = 1;
B = 1;
seg = zeros(1,2);
cr = zeros(1,4);
FdB = zeros(1,2);
for i = 1:901
    if line(i,1) ~= 0 && (i>=2 && abs(line(i-1,2)-line(i,2)) <=5)
       seg(A,1) = line(i,1);
       seg(A,2) = line(i,2);
       A = A+1;
    else
       if size(seg,1) >= 2 
          [cir, radius, x_center, y_center, yes] = cal_cr(seg);
          if (yes == 1)
              cr(B,1) = cir;
              cr(B,2) = radius;
              cr(B,3) = x_center;
              cr(B,4) = y_center;
              
              if 513>=cr(B,3) && cr(B,3)>=505 %509
                    FdB(B,1) = 250;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 650>=cr(B,3) && cr(B,3)>=644 %647
                    FdB(B,1) = 500;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 735>=cr(B,3) && cr(B,3)>=727 %731
                    FdB(B,1) = 750;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 794>=cr(B,3) && cr(B,3)>=786 %790
                    FdB(B,1) = 1000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 876>=cr(B,3) && cr(B,3)>=868 %872
                    FdB(B,1) = 1500;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 932>=cr(B,3) && cr(B,3)>=924 %928
                    FdB(B,1) = 2000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 1016>=cr(B,3) && cr(B,3)>=1008 %1012
                    FdB(B,1) = 3000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 1075>=cr(B,3) && cr(B,3)>=1067 %1071
                    FdB(B,1) = 4000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 1154>=cr(B,3) && cr(B,3)>=1146 %1150
                    FdB(B,1) = 6000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
               elseif 1213>=cr(B,3) && cr(B,3)>=1205 %1209
                    FdB(B,1) = 8000;
                    if 596>=cr(B,4) && cr(B,4)>=585 %593
                        FdB(B,2) = -5;
                    elseif 635>=cr(B,4) && cr(B,4)>=623 %631
                        FdB(B,2) = 0;
                    elseif 673>=cr(B,4) && cr(B,4)>=661 %669
                        FdB(B,2) = 5;
                    elseif 712>=cr(B,4) && cr(B,4)>=700 %708
                        FdB(B,2) = 10;
                    elseif 750>=cr(B,4) && cr(B,4)>=738 %746
                        FdB(B,2) = 15;
                    elseif 788>=cr(B,4) && cr(B,4)>=776 %784
                        FdB(B,2) = 20;
                    elseif 826>=cr(B,4) && cr(B,4)>=814 %822
                        FdB(B,2) = 25;
                    elseif 864>=cr(B,4) && cr(B,4)>=852 %860
                        FdB(B,2) = 30;
                    elseif 892>=cr(B,4) && cr(B,4)>=890 %898
                        FdB(B,2) = 35;
                    elseif 940>=cr(B,4) && cr(B,4)>=928 %936
                        FdB(B,2) = 40;
                    elseif 978>=cr(B,4) && cr(B,4)>=966 %974
                        FdB(B,2) = 45;
                    elseif 1016>=cr(B,4) && cr(B,4)>=1004 %1012
                        FdB(B,2) = 50;
                    elseif 1054>=cr(B,4) && cr(B,4)>=1044 %1050
                        FdB(B,2) = 55;
                    elseif 1092>=cr(B,4) && cr(B,4)>=1080 %1088
                        FdB(B,2) = 60;
                    elseif 1130>=cr(B,4) && cr(B,4)>=1118 %1126
                        FdB(B,2) = 65;
                    elseif 1168>=cr(B,4) && cr(B,4)>=1156 %1164
                        FdB(B,2) = 70;
                    elseif 1206>=cr(B,4) && cr(B,4)>=1194 %1202
                        FdB(B,2) = 75;
                    elseif 1240>=cr(B,4) && cr(B,4)>=1232 %1240
                        FdB(B,2) = 80;
                    elseif 1282>=cr(B,4) && cr(B,4)>=1270 %1278
                        FdB(B,2) = 85;
                    elseif 1320>=cr(B,4) && cr(B,4)>=1312 %1312
                        FdB(B,2) = 90;
                    elseif 1358>=cr(B,4) && cr(B,4)>=1346 %1354
                        FdB(B,2) = 95;
                    elseif 1396>=cr(B,4) && cr(B,4)>=1384 %1392
                        FdB(B,2) = 100;
                    elseif 1434>=cr(B,4) && cr(B,4)>=1422 %1430
                        FdB(B,2) = 105;
                    elseif 1472>=cr(B,4) && cr(B,4)>=1460 %1468
                        FdB(B,2) = 110;
                    elseif 1510>=cr(B,4) && cr(B,4)>=1498 %1506
                        FdB(B,2) = 115;
                    elseif 1548>=cr(B,4) && cr(B,4)>=1536 %1544
                        FdB(B,2) = 120;
                    end
              end
              B = B + 1;
          end
          seg = zeros(1,2);
          A = 1;
          
       end
    end
    
end
%circle detection end


imshow(im)
function [circularity, radius, x_center, y_center, yes]= cal_cr(data)
    yes = 0;
    n = size(data,1);
    x = data(:, 1);
    y = data(:, 2);
    A = [-2*x -2*y ones(n, 1)];
    b = -x.^2 - y.^2;

    x_p = A\b;
    xc = x_p(1);
    yc = x_p(2);
    radius = sqrt(xc^2 + yc^2 - x_p(3));
    circularity = sum( ( radius - sqrt((xc-x).^2 + (yc-y).^2) ).^2 );
    if mod(size(data,1),2) == 1
        x_center = (data(1,1) + data(size(data,1),1))/2;
        y_center = ceil((data(1,2) + data(size(data,1),2))/2);
    else
        x_center = (data(1,1) + data(size(data,1)-1,1))/2;
        y_center = ceil((data(1,2) + data(size(data,1)-1,2))/2);
    end
    if ((circularity <= 4) && (circularity >= 2.2)) || ((radius <= 24.5) && (radius >= 23))
        yes = 1;
    end

end

