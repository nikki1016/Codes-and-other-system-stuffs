clear;

img = imread('face.jpg');

imgG = rgb2gray(img);

n4 = bwconncomp(imgG, 4);
n8 = bwconncomp(imgG, 8);

display(n4.NumObjects);
display(n8.NumObjects);

level = graythresh(img);
BW = im2bw(img, level);

L = bwlabel(BW,4);

Y = bwlabel(BW);
m1 = max(Y(:));

m  = max(L(:));
imshow(L);