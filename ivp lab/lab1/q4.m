%Using ‘for loop’ access the column nos. from 15 to 60 of rows 8 to 30 of the given image and
%display the same.
[panda, map] =imread('cameraman.tif');
panda_int8=int8(panda);
arr=zeros(28, 45,'uint8'); 
for i=8:30
   for j = 15:60
        arr(i-7,j-14)= panda_int8(i,j,1);
   end
end
    hold on
    imshow(arr);
    hold on
