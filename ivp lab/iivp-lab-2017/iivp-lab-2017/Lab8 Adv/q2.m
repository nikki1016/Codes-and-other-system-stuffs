clear;
img = imread('face.jpg');
img = rgb2gray(img);
SobelImg1 = zeros(size(img));
PrewittImg1 = zeros(size(img));
S1=[-1 0 1;-2 0 2; -1 0 1];
S2=[-1 -2 -1;0 0 0; 1 2 1];
img=double(img);
for i=1:size(img,1)-2
    for j=1:size(img,2)-2
        Gx=sum(sum(S1.*img(i:i+2,j:j+2)));
        Gy=sum(sum(S2.*img(i:i+2,j:j+2)));              
        SobelImg1(i+1,j+1)=sqrt(Gx.^2+Gy.^2);
    end
end
SobelImg1 = uint8(SobelImg1);
P1=[1 0 -1;1 0 -1; 1 0 -1];
P2=[1 1 1;0 0 0; -1 -1 -1];
for i=1:size(img,1)-2
    for j=1:size(img,2)-2
        Gx=sum(sum(P1.*img(i:i+2,j:j+2)));
        Gy=sum(sum(P2.*img(i:i+2,j:j+2)));              
        PrewittImg1(i+1,j+1)=sqrt(Gx.^2+Gy.^2);
    end
end
PrewittImg1 = uint8(PrewittImg1);

img = uint8(img);
hold on;
subplot(3, 1, 1), imhist(img-SobelImg1), title('Histogram for Image - Sobel');
subplot(3, 1, 2), imhist(img-PrewittImg1), title('Histogram for Image - Prewitt');
subplot(3, 1, 3), imhist(SobelImg1-PrewittImg1), title('Histogram for Sobel - Prewitt');