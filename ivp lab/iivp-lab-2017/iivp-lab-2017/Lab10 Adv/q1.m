X = (imread('Image_4.bmp'));
l = [0:length(X)-1];
FX=fft2(X);
MFX=abs(FX);
figure
imshow(fftshift(log(MFX +1)));
imagesc(fftshift(log(MFX +1)))