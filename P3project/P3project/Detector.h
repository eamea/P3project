#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

class Detector
{
public:
	Detector(int kSize);			//Constructor that sets the kernel size
	Mat segmentFrame(Mat src);		//Returns a Mat that has been segmented with HSV values.
	void createTrackbars();			//creates a windows called "control" with trackbars for setting HSV values.
	void setThreshold(char color);	//Thresholds based on the car inserted. b = blue, g = green, p = pink, r = red, y = yellow.
private:
	int kernelSize;				//the kernel size to use during morphological operations

	int iLowH = 0;				//Basic int values for Hue (0-179), Saturation (0-255) and Value (0-255)
	int iHighH = 179;			
	int iLowS = 0;
	int iHighS = 255;
	int iLowV = 0;
	int iHighV = 255;
};

