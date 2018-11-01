img=imread('Image.jpg');

num_of_pixels=size(img,1)*size(img,2);
%figure,imshow(img);
%title('Original Image');

HIm=uint8(zeros(size(img,1),size(img,2)));
HIM2=int8('Image.jpg');

freq=zeros(256,1);
probf=zeros(256,1);
probc=zeros(256,1);
cum=zeros(256,1);
output=zeros(256,1);

%freq counts the occurrence of each pixel value.
%The probability of each occurrence is calculated by probf.

for i=1:size(img,1)

    for j=1:size(img,2)

        value=img(i,j);

        freq(value+1)=freq(value+1)+1;

        probf(value+1)=freq(value+1)/num_of_pixels;

    end

end


sum=0;

no_bins=255;


%The cumulative distribution probability is calculated. 

for i=1:size(probf)

   sum=sum+freq(i);

   cum(i)=sum;

   probc(i)=cum(i)/num_of_pixels;

   output(i)=round(probc(i)*no_bins);

end

for i=1:size(img,1)

    for j=1:size(img,2)

            HIm(i,j)=output(img(i,j)+1);

    end

end

figure,imshow(HIm);

title('Histogram equalization');
figure,imshow(HIM2);

title('Histogram equalization');