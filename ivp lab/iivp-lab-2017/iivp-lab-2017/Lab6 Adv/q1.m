clear;
img = imread('face.jpg');
img = rgb2gray(img);
hold on;
subplot(3, 3, 1), subimage(img), title('Original');

[m n] = size(img);

imgM = zeros(m,n);
imgL = zeros(m,n);

counterM = zeros(256);
counterL = zeros(256);

for i = 1:m
    for j = 1:n
        if img(i,j) > 127
            imgM(i,j) = 255;
            counterM(256) = counterM(256)+1;
        else
            imgM(i,j) = 0;
            counterM(1) = counterM(1)+1;
        end
    end
end
subplot(3, 3, 2), subimage(imgM), title('MSB');
subplot(3, 3, 3), bar([0:255], counterM), title('MSB Histogram');

for i = 1:m
    for j = 1:n
        if (mod(img(i,j),2) == 0 )
            imgL(i,j) = 0;
            counterL(1) = counterM(1)+1;
        else
            imgL(i,j) = 255;
            counterL(256) = counterM(256)+1;
        end
    end
end
subplot(3, 3, 4), subimage(imgL), title('LSB');
subplot(3, 3, 5),  bar([0:255], counterL), title('LSB Histogram');

