clear;
img = imread('face.jpg');
hold on;
subplot(3, 2, 1), subimage(img), title('Original');
img = rgb2gray(img);
hold on;
subplot(3, 2, 2), subimage(img), title('Grayscale');
SobelImg1 = zeros(size(img));
PrewittImg1 = zeros(size(img));

S1=[-1 0 1;-2 0 2; -1 0 1];
S2=[-1 -2 -1;0 0 0; 1 2 1];

img=double(img);
threshold = -999;

for i=1:size(img,1)-2
    for j=1:size(img,2)-2
        Gx=sum(sum(S1.*img(i:i+2,j:j+2)));
        Gy=sum(sum(S2.*img(i:i+2,j:j+2)));
        temp = atan(Gy/Gx);
        if threshold<temp
            threshold = temp;
        end
        SobelImg1(i+1,j+1)=sqrt(Gx.^2+Gy.^2);
    end
end
threshold
SobelImg1 = uint8(SobelImg1);
subplot(3, 2, 3), subimage(SobelImg1), title('Sobel Filtered Image');
SobelImg2 = max(SobelImg1,threshold);
SobelImg2(SobelImg2==round(threshold))=0;
SobelImg2=im2bw(SobelImg2);
subplot(3, 2, 4), subimage(SobelImg2), title('Sobel Detected Edges');

P1=[1 0 -1;1 0 -1; 1 0 -1];
P2=[1 1 1;0 0 0; -1 -1 -1];

threshold = -999;
for i=1:size(img,1)-2
    for j=1:size(img,2)-2
        Gx=sum(sum(P1.*img(i:i+2,j:j+2)));
        Gy=sum(sum(P2.*img(i:i+2,j:j+2)));
        temp = atan(Gy/Gx);
        if threshold<temp
            threshold = temp;
        end
        PrewittImg1(i+1,j+1)=sqrt(Gx.^2+Gy.^2);
    end
end
threshold
PrewittImg1 = uint8(PrewittImg1);
subplot(3, 2, 5), subimage(PrewittImg1), title('Prewitt Filtered Image');
PrewittImg2 = max(PrewittImg1,threshold);
PrewittImg2(PrewittImg2==round(threshold)) = 0;
PrewittImg2=im2bw(PrewittImg2);
subplot(3, 2, 6), subimage(PrewittImg2), title('Prewitt Detected Edges');
