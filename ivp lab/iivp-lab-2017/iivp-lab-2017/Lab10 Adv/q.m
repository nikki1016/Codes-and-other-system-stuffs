%% Load Image
im1=imread('Image_4.bmp');  %conversion to 16-bit integers
im2=rgb2gray(imread('grid_image.jpg'));
im1=imresize(im1, [256 256]);
% imshow(im);

%% 1 (a) Part
im_f=fftshift(fft2(double(im2)));
ampIm=log(abs(im_f));
imshow(ampIm);

threshold=4.9;
spikes = ampIm > threshold;
subplot(2,2,1);
imshow(spikes);

imshow(spikes);
subplot(2,2,2);
spikes(:,110:140)=0;
spikes(110:140,:)=0;
im1_f(spikes)=0;
subplot(2,2,3);
imshow(spikes);
subplot(2,2,4);
imshow(ifft2(fftshift(im1_f)));
