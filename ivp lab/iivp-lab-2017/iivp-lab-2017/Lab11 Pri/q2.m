clear;
img   = imread('seg_image.jpg'); 
hold on;
subplot(1,2,1), subimage(img), title('Original Image');

level = graythresh(img);
BW = im2bw(img,level);
subplot(1,2,2), imshow(BW), title('Object');
