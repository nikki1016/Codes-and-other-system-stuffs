clear;
EyeDetect = vision.CascadeObjectDetector('EyePairBig');
img = imread('face.jpg');
BB=step(EyeDetect,img);
Eyes=imcrop(img,BB);
eyeSize = size(Eyes);
xValue = eyeSize(1);
eyes_distance = xValue/2
