#pragma once
#include "opencv2/opencv.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <list>

using namespace cv;
using namespace std;

class BLOBDetector
{
public:
	BLOBDetector();												//Empty constructor sets the image.
	Mat BLOBDetection(Mat img, char color);						//BLOB detection goes through rows and cols and checks for all 255 values in the inserted image.
	void grassFire(size_t row, size_t col, Mat img, char color);//Method for detecting BLOBs.
	void visSeqGrassFire(size_t row, size_t col, Mat img, char color);	//visual representation of labeling objects
	void listSeqGrassFire(size_t row, size_t col, Mat img, char color);	//non-visual grassfire. Puts the objects into lists.
	void objectPixelIn(size_t row, size_t col, char color);
	vector<vector<Point>> getBLOBList(char color);
private:
	Mat BLOB;			//Default BLOB image. Will mainly be used in case of an error.
	int object = 50;		//int that categorizes the BLOBs.
	int pointNum;

	Mat blueBLOBImg;
	Mat greenBLOBImg;
	Mat pinkBLOBImg;
	Mat redBLOBImg;
	Mat yellowBLOBImg;

	list<size_t> xCoor;
	list<size_t> yCoor;

	vector<vector<Point>> BLOBList;
	vector<vector<Point>> blueBLOBList;
	vector<vector<Point>> greenBLOBList;
	vector<vector<Point>> pinkBLOBList;
	vector<vector<Point>> redBLOBList;
	vector<vector<Point>> yellowBLOBList;
	vector<Point> points;

	int n = 0;
	int m = 10;
};

