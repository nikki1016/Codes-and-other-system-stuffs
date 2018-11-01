clear;
img = imread('Image_3.bmp');
img1 = imfill(img, 'holes');
hold on;
subplot(3, 1, 1), subimage(img), title('Original');
subplot(3, 1, 2), subimage(img1), title('Holes');
subplot(3, 1, 3), subimage(img1 - img), title('Difference');
