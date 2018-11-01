%Write a program using for loop to implement checker box. The size of the box will be given by
%the user.

x=32;
t = 256/x;
arr=zeros(256, 256, 'uint8');
f=1;
for i=1:t
   for j = 1:t 
       if mod(i+j,2) == 0
            for k = 1: x
                for l = 1:x
                    arr(x*(i-1)+k,x*(j-1)+l) = 0;
                end
            end
       end
       if mod(i+j,2) == 1
           for k = 1: x
                for l = 1:x
                    arr(x*(i-1)+k,x*(j-1)+l) = 255;
                end
            end
           
       end
   end
end
 imshow(arr);
