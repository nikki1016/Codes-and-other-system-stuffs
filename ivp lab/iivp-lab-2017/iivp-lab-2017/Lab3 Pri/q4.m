clear;
img = rgb2gray(imread('face.jpg'));
isize = size(img);
EyeDetect = vision.CascadeObjectDetector('EyePairBig');
isize
BB=step(EyeDetect,img);
BB
im = uint8(zeros(30,61));
im1 = uint8(zeros(30,61));
for i = 67:1:67+30
    for j = 85:1:85+61
        im(i-66,j-84) = img(i,j);
    end
end
for i = 67:1:67+30
    for j = 147:1:147+61
        im1(i-66,j-146) = img(i,j);
    end
end
sum = 0;
for i = 1:30
    for j = 1:61
        sum = sum + (im(i,j)-im1(i,j))^2;
    end
end
disp(sqrt(double(sum)));

