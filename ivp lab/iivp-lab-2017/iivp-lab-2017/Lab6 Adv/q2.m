clear;
img = imread('face.jpg');
img = rgb2gray(img);
hold on;
subplot(1, 3, 1), subimage(img), title('Original');

[m n] = size(img);


temp = mod(m,2);
for k=1:temp
    for j=1:n
        img(m+k, j) = 0;
    end
end
temp = mod(n,2);
for k=1:temp
    for j=1:m
        img(j, n+k) = 0;
    end
end

p = 1;
q = 1;

for i = 1:2:m-1
    q = 1;
    for j = 1:2:n-1
        avg = img(i, j) + img(i+1, j) + img(i, j+1) + img(i+1, j+1);
        avg  = avg/4;
        
        imgAvg(p,q) = avg;
        q = q + 1;
    end
    p = p+1;
end
subplot(1, 3, 2), subimage(imgAvg), title('2*2 Average');

p = 1;
q = 1;

for i = 1:2:m-1
    q = 1;
    for j = 1:2:n-1
        
        A(1) = img(i, j);
        A(2) = img(i+1, j);
        A(3) = img(i, j+1);
        A(4) = img(i+1, j+1);
        
        med = median(A);
        
        imgMed(p,q) = med;
        q = q + 1;
    end
    p = p+1;
end
subplot(1, 3, 3), subimage(imgMed), title('2*2 Median');

size(img)
size(imgAvg)

