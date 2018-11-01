clc;
clear;
fontSize = 15;
folder = pwd;
baseFileName = 'grid_image.jpg';
% Get the full filename, with path prepended.
fullFileName = fullfile(folder, baseFileName);
if ~exist(fullFileName, 'file')
	% Didn't find it there.  Check the search path for it.
	fullFileName = baseFileName; % No path this time.
	if ~exist(fullFileName, 'file')
		% Still didn't find it.  Alert user.
		errorMessage = sprintf('Error: %s does not exist.', fullFileName);
		uiwait(warndlg(errorMessage));
		return;
	end
end
grayImage = rgb2gray(imread('grid_image.jpg'));
% Get the dimensions of the image.  numberOfColorBands should be = 1.
[rows columns numberOfColorBands] = size(grayImage);
% Display the original image.
subplot(2, 2, 1);
imshow(grayImage);
axis on;
title('Original Gray Scale Image', 'FontSize', fontSize);
set(gcf, 'Position', get(0,'Screensize')); 
% Let's compute and display the histogram.
[pixelCount, grayLevels] = imhist(grayImage);
subplot(2, 2, 2); 
bar(grayLevels, pixelCount);
grid on;
title('Histogram of original image', 'FontSize', fontSize);
xlim([0 grayLevels(end)]); % Scale x axis manually.
% Median Filter the image:
medianFilteredImage = medfilt2(grayImage, [23 23]);
% Find the noise.  It will have a gray level of either 0 or 255.
noiseImage = grayImage > 125;
% Display the image.
subplot(2, 2, 3);
imshow(noiseImage);
axis on;
title('Noise', 'FontSize', fontSize);
% Get rid of the noise by replacing with median.
noiseFreeImage = grayImage; % Initialize
noiseFreeImage(noiseImage) = medianFilteredImage(noiseImage); % Replace.
% Display the image.
subplot(2, 2, 4);
imshow(noiseFreeImage);
axis on;
title('Restored Image', 'FontSize', fontSize);