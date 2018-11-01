clear;
I   = imread('seg_image.jpg'); 
hold on;
subplot(1,3,1), subimage(I), title('Original Image');

level = multithresh(I,1);
seg_I = imquantize(I,level);
subplot(1,3,2), imshow(seg_I,[]), title('Multi Level Threshold');

thresh = multithresh(I,2);
seg_I = imquantize(I,thresh);
RGB = label2rgb(seg_I);
subplot(1,3,3), imshow(RGB), title('RGB Segmented');

