[panda, map] =imread('cameraman.tif');
%imshow(panda)
panda_int8=int8(panda);
panda_uint8=uint8(panda);

panda_single=im2single(panda);
panda_double=im2double(panda);
panda_int16=im2int16(panda);
panda_uint16=im2uint16(panda);
hold on;
subplot(4,2,1), subimage(panda), title('normal');
% subplot(4,2,2), subimage(panda_int8), title('int8');
 subplot(4,2,2), subimage(panda_uint8), title('uint8');
 subplot(4,2,3), subimage(panda_single), title('single');
 subplot(4,2,4), subimage(panda_double), title('double');
 subplot(4,2,5), subimage(panda_uint16), title('uint16');