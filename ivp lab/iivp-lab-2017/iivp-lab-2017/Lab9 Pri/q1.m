clear;
img = imread('Image_1.bmp');
img1 = img;
hold on;
subplot(2, 3, 1), subimage(img1), title('Original');
se1 = strel('square', 5);

for k = 1:6
    img1 = imerode(img1, se1);
end
subplot(2, 3, 2), subimage(img1), title('Eroded');
subplot(2, 3, 3), subimage(img - img1), title('Original - Eroded');

img2 = img;
for k = 1:6
    img1 = imdilate(img1, se1);
end
subplot(2, 3, 4), subimage(img), title('Original');
subplot(2, 3, 5), subimage(img2), title('Dilated');
subplot(2, 3, 6), subimage(img2 - img), title('Original - Dilated');
