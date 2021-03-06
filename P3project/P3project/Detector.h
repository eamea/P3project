#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

class Detector
{
public:
	Detector();
	Detector(int kSize);							//constructor to set the kernel size
	void createTrackbars();							//creates a windows called "control" with trackbars for setting HSV values
	void setThreshold(char color);					//sets thresholds based on the char inserted. b = blue, g = green, p = pink, r = red, y = yellow
	void thresholdImageFor(Mat src, char letter);	//thresholds only the colors that are needed for the specific letter
	void thresholdForGlove2(Mat src);				//thresholds all images (glove2 needs all colors thresholded)
	Mat segmentFrame(Mat src);						//returns a Mat that has been segmented with HSV values

	Mat getBlueThreshImg();							//getter-functions for each thresholded image
	Mat getGreenThreshImg();
	Mat getPinkThreshImg();
	Mat getRedThreshImg();
	Mat getYellowThreshImg();
private:
	int kernelSize;									//the kernel size to use during morphological operations

	int iLowH = 0;									//basic int values for Hue (0-179), Saturation (0-255) and Value (0-255)
	int iHighH = 179;			
	int iLowS = 0;
	int iHighS = 255;
	int iLowV = 0;
	int iHighV = 255;

	//Mats to hold the thresholded images
	Mat blueThreshImg;
	Mat greenThreshImg;
	Mat pinkThreshImg;
	Mat redThreshImg;
	Mat yellowThreshImg;
};

