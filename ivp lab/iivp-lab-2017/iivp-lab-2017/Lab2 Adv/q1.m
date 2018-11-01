clear;
img = imread('Image.jpg');
grayImg = rgb2gray(img);
doubleImg = im2double(grayImg);
[m n] = size(doubleImg);

c = 2;
g =[0.8 1 3 5 6];
hold on;
subplot(2,3,1), subimage(img), title(1);
for r=1:length(g)
    for p = 1 : m
        for q = 1 : n
            I(p, q) = c * doubleImg(p, q).^ g(r);
        end
    end
    subplot(2,3,r+1), subimage(I), title(r+1);
end