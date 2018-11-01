clear;
A   = imread('Image_1.bmp'); 
hold on;
subplot(1,3,1), subimage(A), title('Original Image');
B=getnhood(strel('disk',11));

m=floor(size(B,1)/2);
n=floor(size(B,2)/2);
%Pad array on all the sides
C=padarray(A,[m n],1);
%Intialize a matrix with size of matrix A
D=false(size(A));
for i=1:size(C,1)-(2*m)
    for j=1:size(C,2)-(2*n)
        Temp=C(i:i+(2*m),j:j+(2*n));
        D(i,j)=min(min(Temp-B));
    end
end
D = ~D;
subplot(1,3,2), subimage(D), title('Eroded image');

B2=getnhood(strel('line',7,90));
m=floor(size(B2,1)/2);
n=floor(size(B2,2)/2);
%Pad array on all the sides
C=padarray(A,[m n]);
D=false(size(A));
for i=1:size(C,1)-(2*m)
    for j=1:size(C,2)-(2*n)
        Temp=C(i:i+(2*m),j:j+(2*n));
        D(i,j)=max(max(Temp&B2));
    end
end
subplot(1,3,3), subimage(D), title('Dilated Image');
