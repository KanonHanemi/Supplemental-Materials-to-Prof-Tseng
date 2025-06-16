clear;clc;
A = zeros(197);
for i = 1:196
    A(i,i+1) = -1;
    A(i+1,i) = -1;
    A(i,i) = 2;
end
A(197,197) = 2;
det(A)