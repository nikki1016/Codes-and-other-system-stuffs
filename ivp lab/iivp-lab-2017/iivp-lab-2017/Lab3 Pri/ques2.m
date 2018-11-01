clear;

I = imread('face.jpg');

level = graythresh(I);
BW = im2bw(I, level);

L = bwlabel(BW,4);

Y = bwlabel(BW);
m1 = max(Y(:));

m  =max(L(:));
imshow(L);