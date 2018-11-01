clear;
img=imread('Image.jpg');
angle=180;

%Find the midpoint
if(angle>155)
    midx = ceil((size(img,1))/2);
    midy = ceil((size(img,2))/2);
else
    midx = ceil((size(img,2))/2);
    midy = ceil((size(img,1))/2);
end

[y,x] = meshgrid(1:size(img,2), 1:size(img,1));
[t,r] = cart2pol(x-midx,y-midy);
t1 =  (t*180 *7)/22+angle;
%Convert from degree to radians
t = (t1 *22 )/(180*7);
%Convert to Cartesian Co-ordinates
[x,y] = pol2cart(t,r);
tempx = round(x+midx);
tempy = round(y+midy);

if ( min(tempx ( : ) ) < 0 )
    newx = max(tempx(:))+abs(min(tempx(:)))+1;
    tempx = tempx+abs(min(tempx(:)))+1;
else
    newx = max(tempx(:));
end

if( min(tempy ( : ) ) < 0 )
    newy = max(tempy(:)) + abs(min(tempy(:)))+1;
    tempy = tempy + abs(min(tempy(:)))+1;
else
    newy = max(tempy(:));
end

tempy(tempy==0) = 1;
tempx(tempx==0) = 1;

C = uint8(zeros([newx newy 3]));

for i = 1:size(img,1)
    for j = 1:size(img,2)
        C( tempx(i,j),tempy(i,j) ,:) = img(i,j,:);
    end  
end

title('Rotated');
hold on;
subplot(1,2,1), subimage(img), title('Original');
subplot(1,2,2), subimage(C), title('Rotated');