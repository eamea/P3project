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
	BLOBDetector();												
	Mat BLOBDetection(Mat img, char color);								//applies grassfire to img, and parses list of BLOBs to relevant color BLOBList
	vector<vector<Point>> getBLOBList(char color);						//returns the BLOBList for the color parsed to the function
private:
	void seqGrassFire(size_t row, size_t col, Mat img, char color);		//sequential grassfire algorithm
	void objectPixelIn(size_t row, size_t col, char color);				//setting current pixel in relevant BLOBImg to the current object label value

	Mat BLOB;															//default BLOB image, will mainly be used in case of error
	int object = 50;													//object label
	int BLOBsizeToFilterOut = 5;										//BLOBs below this pixel amount will not be counted as a BLOB

	list<size_t> xCoor;													//list of coordinates for object pixels not yet checked
	list<size_t> yCoor;

	vector<Point> points;												//holds the points of a single BLOB

	vector<vector<Point>> BLOBList;										//holds list of BLOBs to be parsed to a color-specific list

	vector<vector<Point>> blueBLOBList;									//color-specific lists of BLOBs
	vector<vector<Point>> greenBLOBList;
	vector<vector<Point>> pinkBLOBList;
	vector<vector<Point>> redBLOBList;
	vector<vector<Point>> yellowBLOBList;

	Mat blueBLOBImg;													//Mats to hold BLOB-analyzed images
	Mat greenBLOBImg;
	Mat pinkBLOBImg;
	Mat redBLOBImg;
	Mat yellowBLOBImg;
};

