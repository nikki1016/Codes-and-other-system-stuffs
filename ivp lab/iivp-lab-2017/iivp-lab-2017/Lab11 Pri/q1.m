clear;
img   = imread('seg_image.jpg'); 
hold on;
subplot(1,2,1), subimage(img), title('Original Image');

mask = zeros(size(img));
mask(50:end-50,50:end-50) = 1;

bw = activecontour(img,mask,300);
subplot(1,2,2), subimage(bw), title('Segmented Image');
