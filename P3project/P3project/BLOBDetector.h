#pragma once
#include "opencv2/opencv.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

class BLOBDetector
{
public:
	BLOBDetector();								//Empty constructor sets the image.
	Mat BLOBDetection(Mat img, char color);	//BLOB detection goes through rows and cols and checks for all 255 values in the inserted image.
	void grassFire(size_t row, size_t col, Mat img, char color);		//Method for detecting BLOBs.
	//Mat  returnBLOB();							//Returns the BLOB image.

private:
	Mat image;									//The image we work with.
	Mat BLOB;									//The image that contains the BLOBs.
	int object = 1;								//int that categorizes the BLOBs.

	Mat blueBLOBImg;
	Mat greenBLOBImg;
	//Mat pinkBLOBImg;
	Mat redBLOBImg;
	Mat yellowBLOBImg;
};

