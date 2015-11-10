#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class Bounder
{
public:
	Bounder();							//constructor
	void setInputImg(Mat src);
	void setContours(Mat src);			//finds contours in the inserted image, saves them in the variable "contours".
	Mat contourImage();					//returns an image where contours for the input image have been drawn
	Mat boundingBox(int minArea);		//returns an image where boundingRects+centers for the input image have been drawn
private:
	Mat inputImg;
	
	Mat contourImg;					//for drawing found contours onto an image
	Mat rectImg;					//for drawing the bounding rects and their centers in an image

	vector<vector<Point>> contours;	//for holding the points of the contours found
	Rect rect;						//bounding box variable
	Point pt1, pt2, center;			//pt1/pt2 are for drawing the boundingRect intself, center is for drawing the center.
};

