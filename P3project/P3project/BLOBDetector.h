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
	BLOBDetector(Mat thresImg);
	void BLOBDetection();
	void grassFire(size_t row, size_t col); //temporary method for detecting the BLOB's
	Mat  returnBLOB();

private:
	Mat img;
	vector < KeyPoint >  BLOBVectors;
	Mat BLOB;
	int object = 1;
};

