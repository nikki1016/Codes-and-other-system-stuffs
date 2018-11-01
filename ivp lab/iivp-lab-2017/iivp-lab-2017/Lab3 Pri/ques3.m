clear;
%Read the input image 
img = imread('face.jpg');

%To detect Mouth
MouthDetect = vision.CascadeObjectDetector('Mouth','MergeThreshold',16);
BB=step(MouthDetect,img);
figure,
imshow(img); hold on
for i = 1:size(BB,1)
 rectangle('Position',BB(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','r');
end

%To detect Mouth
NoseDetect = vision.CascadeObjectDetector('Nose','MergeThreshold',16);
BB=step(MouthDetect,img);
hold on
rectangle('Position',BB,'LineWidth',4,'LineStyle','-','EdgeColor','g');

%To detect Eyes
EyeDetect = vision.CascadeObjectDetector('EyePairBig');
BB=step(EyeDetect,img);
hold on
rectangle('Position',BB,'LineWidth',4,'LineStyle','-','EdgeColor','b');

