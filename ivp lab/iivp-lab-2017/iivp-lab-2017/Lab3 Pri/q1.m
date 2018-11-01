clear;
face = imread('face.jpg');
hold on;
subplot(4,2,1), subimage(face), title('normal');

img = rgb2gray(face);
subplot(4,2,2), subimage(img), title('grayscale');

imgGauss = imnoise(img,'gaussian',0.025);
subplot(4,2,3), subimage(imgGauss), title('gaussian noise');

imgGaussRem = wiener2(imgGauss,[5 5]);
subplot(4,2,4), subimage(imgGaussRem), title('gaussian noise removal');

imgSalt = imnoise(img,'salt & pepper',0.02);
subplot(4,2,5), subimage(imgSalt), title('salt & pepper noise');

imgSaltRem = medfilt2(imgSalt);
subplot(4,2,6), subimage(imgSaltRem), title('salt & pepper noise removal');

imgPois = imnoise(img,'poisson');
subplot(4,2,7), subimage(imgPois), title('poisson noise');

imgPoisRem = wiener2(imgPois,[5 5]);
subplot(4,2,8), subimage(imgPoisRem), title('poisson noise removal');


