clear;
newImg = imread('Earth.jpg');
newImg = rgb2gray(newImg);

hold on;
subplot(2,3,1), subimage(newImg), title('Original');

H = fspecial('laplacian', 0.5);
img1 = imfilter(newImg,H);
subplot(2,3,2), subimage(img1), title('a. Laplacian Filter Scaling');

newImg1 = conv2(im2double(newImg), im2double(img1));
subplot(2,3,3), subimage(newImg1), title('Original + (a)');

J = fspecial('laplacian');
img2 = imfilter(newImg,J);
subplot(2,3,4), subimage(img2), title('b. Laplacian Filter No Scaling');

newImg2 = conv2(im2double(newImg), im2double(img2));
subplot(2,3,5), subimage(newImg2), title('Original + (b)');
