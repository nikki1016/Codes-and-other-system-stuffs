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
