clear;
newImg = imread('Earth.jpg');
newImg = rgb2gray(newImg);

hold on;
subplot(2,3,1), subimage(newImg), title('Original');

H = fspecial('laplacian');
J = fspecial('laplacian', 0.5);

img1 = imfilter(newImg,H);
img2 = imfilter(newImg,J);

subplot(2,3,2), subimage(img1), title('a. Laplacian Filter Scaling');
subplot(2,3,3), subimage(img1), title('b. Laplacian Filter No Scaling');

newImg1 = conv2(im2double(newImg), im2double(img1));
subplot(2,3,4), subimage(newImg1), title('Original + (a)');

newImg2 = conv2(im2double(newImg), im2double(img2));
subplot(2,3,5), subimage(newImg2), title('Original + (b)');
