clear;
img = imread('Image_2.bmp');
hold on;
subplot(2, 1, 1), subimage(img), title('Original');
se1 = strel('square', 5);
img = imopen(img, se1);
img = imclose(img, se1);
subplot(2, 1, 2), subimage(img), title('Noise Removed');

