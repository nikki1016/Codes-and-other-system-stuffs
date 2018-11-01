clear;
face=imread('face.jpg');
img=rgb2gray(face);

hold on;
subplot(2,2,1), subimage(img), title('grayscale image');

eye=imcrop(img,[90 65 110 30]);
subplot(2,2,2), subimage(eye), title('eyes');

eye_left=imcrop(img,[90 65 55 30]);
subplot(2,2,3), subimage(eye_left), title('left eye');

eye_right=imcrop(img,[145 65 55 30]);
subplot(2,2,4), subimage(eye_right), title('right eye');

x=size(eye_left,1);
y=size(eye_left,2);

sum=0.0;
diff=0.0;

for i=1:1:x
    for j=1:1:y
        diff=im2double(eye_left(i,j)-eye_right(i,y-j+1));
        diff=im2double(diff.*diff);
        sum=sum+diff;
    end
end
sum1=im2double(sqrt(sum));
disp(sum1);