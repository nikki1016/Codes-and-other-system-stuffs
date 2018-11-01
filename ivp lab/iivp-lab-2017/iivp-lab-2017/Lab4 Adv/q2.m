clear;
img = imread('1.png');
freq = zeros([256 1]);
[m, n] = size(img(:,:,1));

for p = 1:m
    for q = 1:n
        for r = 1:3
            freq(img(p,q,r)+1) = freq(img(p,q,r)+1) + 1;
        end
    end
end

q = [1,3,6,7,6,7,6 ];
