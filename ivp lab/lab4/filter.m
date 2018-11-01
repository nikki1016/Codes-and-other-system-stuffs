clear;
pkg load image;

I = imread("Lenna.png");
img = rgb2gray(I);

hold on;
subplot(2,2,1), subimage(I), title('Original');

img_blur = imgaussfilt(img, 2);
subplot(2,2,2), subimage(img_blur), title('Blurred');

[m n] = size(img);

for i = 1:m
    for j = 1:n
        mask(i,j) = img_blur(i,j) - img(i,j);
    end
end

for i = 1:m
    for j = 1:n
        new_img(i,j) = mask(i,j) + img(i,j);
    end
end

subplot(2,2,3), subimage(new_img), title('Final = Image + Mask');