%Access the rows from 25 to 50 of the given image and show the accessed part.
pkg load image
a=imread('Lenna.png');
b = rgb2gray(a);
imshow(b);