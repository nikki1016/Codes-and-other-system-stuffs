clear all;
clc
b = imread("pout.jpg");
%b = rgb2gray(a);
[r c] =size(b);
t = imhist(b);
I2 = histeq(b);
figure
subplot(2,2,1), subimage(b), title('Original Image');
subplot(2,2,2), imhist(b), title('histogram ');
subplot(2,2,3), subimage(I2), title('Histogram equalization');
subplot(2,2,4), imhist(I2), title('histogram ');
