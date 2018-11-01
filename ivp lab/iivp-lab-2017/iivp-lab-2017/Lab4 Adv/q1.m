clear;
img1 = imread('Image1.jpg');
img2 = imread('Image2.jpg');
[m n] = size(img1(:,:,1));
imresize(img2, [m, n]);
min = 99999999;
max = -99999999;
w1 = 0.5;
w2 = 0.5;
for p = 1 : m
    for q = 1 : n
        I(p, q) = w1*img1(p,q)+ w2*img2(p,q);
        if I(p,q) > max
            max = I(p,q);
        end
        if I(p,q) < min
            min = I(p,q);
        end
    end
end

hold on;
subplot(2,2,1), subimage(img1), title('First Image');
subplot(2,2,2), subimage(img2), title('Second Image');
subplot(2,2,3), subimage(I), title('Equally-weighted sum');

max
min