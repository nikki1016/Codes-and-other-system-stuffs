x=8;
t = 256/x;
arr=zeros(x*t, x*t, 'uint8');
f=1;
for i=1:t
   for j = 1:t 
       if mod(i+j,2) == 0
            for k = 1: t
                for l = 1:t
                    arr(i*x+k,j*x+l) = 0;
                end
            end
       end
       if mod(i+j,2) == 1
           for k = 1: t
                for l = 1:t
                    arr(i*x+k,j*x+l) = 255;
                end
            end
           
       end
   end
end
    %hold on
 imshow(arr);
    hold on
