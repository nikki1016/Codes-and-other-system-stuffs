pkg load image;
clear all;
clc
b = imread("cameraman.tif");
%b = rgb2gray(a);
[r c] =size(b)
rmin = min(min(b))
rmax = max(max(b))
for i=1:r
   for j = 1:c 
     if b(i,j) < rmin
        y(i,j) = 0;
      elseif b(i,j) > rmax
        y(i,j) = 255;
      else
        y(i,j) = b(i,j)*2 + rmin;
      end    
   end
 end
 
 r2 = input("r2 :")
 r3 = input("r3: ");
 
for i=1:r
   for j = 1:c 
     if b(i,j) < r2
        x(i,j) = 0;
      elseif b(i,j) > r3
        x(i,j) = 255;
      else
        x(i,j) = b(i,j)*2 + r2;
      end  
   end
 end
subplot(2,2,2), subimage(b), title('Original Image');
subplot(2,2,3), subimage(y), title('Contrast stretching');
subplot(2,2,4), subimage(x), title('Contrast stretching for user input');
