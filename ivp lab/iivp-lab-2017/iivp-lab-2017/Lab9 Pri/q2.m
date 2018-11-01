clear;
img = imread('Image_2.bmp');
img1 = img;
hold on;
subplot(3, 1, 1), subimage(img1), title('Original');
se1 = strel('square', 5);

for k = 1:6
    img1 = imerode(img1, se1);
end

for k = 1:6
    img1 = imdilate(img1, se1);
end
subplot(3, 1, 2), subimage(img1), title('Noise Removed');
subplot(3, 1, 3), subimage(img - img1), title('Difference');