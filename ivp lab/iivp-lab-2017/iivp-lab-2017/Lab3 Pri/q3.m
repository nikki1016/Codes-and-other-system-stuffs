clear;
FDetect = vision.CascadeObjectDetector;
I = imread('face.jpg');

BB = step(FDetect,I);
figure,
imshow(I); hold on;
for i = 1:size(BB,1)
    rectangle('Position',BB(i,:),'LineWidth',5,'LineStyle','-','EdgeColor','b');
end

NoseDetect = vision.CascadeObjectDetector('Nose','MergeThreshold',16);
BB=step(NoseDetect,I);
for i = 1:size(BB,1)
    rectangle('Position',BB(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','r');
end

MouthDetect = vision.CascadeObjectDetector('Mouth','MergeThreshold',50);
BB=step(MouthDetect,I);
for i = 1:size(BB,1)
 rectangle('Position',BB(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','g');
end

EyeDetect = vision.CascadeObjectDetector('EyePairBig');
BB=step(EyeDetect,I);
rectangle('Position',BB,'LineWidth',4,'LineStyle','-','EdgeColor','y');

