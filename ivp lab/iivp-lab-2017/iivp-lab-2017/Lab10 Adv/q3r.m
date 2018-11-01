img   = imread('Image_4.bmp'); 

%psd = (abs(fftshift(fft2(img))).^2 );
psd = 10*log10(abs(fftshift(fft2(img))).^2 );
subplot(2,3,1)
mesh(psd);
title('Frequency Spectrum');

grayImage = rgb2gray( imread('grid_image.jpg'));
[rows columns ] = size(grayImage);

subplot(2, 3, 2);
imshow(grayImage);
title('Gray Scale Image');

[pixelCount, grayLevels] = imhist(grayImage);
subplot(2, 3, 3); 

bar(grayLevels, pixelCount);
title('Histogram ofimage');
xlim([0 grayLevels(end)]); 

medianFilteredImage = medfilt2(grayImage, [23 23]);


noiseImage = grayImage > 125;
x = imread('Image_4.bmp')
subplot(2, 3, 4);
imshow(x);
axis on;

noiseFreeImage = grayImage; 
noiseFreeImage(noiseImage) = medianFilteredImage(noiseImage); % Replace.

subplot(2, 3, 5);
imshow(noiseFreeImage);

title('Restored Image');
