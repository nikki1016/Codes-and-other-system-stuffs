clear;
img   = imread('seg_image.jpg'); 
hold on;
subplot(1,2,1), subimage(img), title('Original Image');

I = im2double(img);
I = regiongrowing(I,102,100);
subplot(1,2,2), subimage(I), title('Foreground Boundary');
