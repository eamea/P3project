#include "Bounder.h"


Bounder::Bounder(){
	inputImg = Mat::zeros(1, 1, CV_8UC3); //while no input image has been set, it is just a black pixel
}

void Bounder::setInputImg(Mat src){
	inputImg = src;
}

void Bounder::setContours(Mat src){
	findContours(src, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0, 0));	//finding contours, filling up the vector-list contours
}

Mat Bounder::contourImage(){
	Mat result = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC3);

	setContours(inputImg);

	//drawing contours
	for (int i = 0; i < contours.size(); i++){
		drawContours(result, contours, i, Scalar(0,0,255));
	}

	return result;
}

Mat Bounder::fixedBoundingBox(int minArea){
	Mat result = Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC3);

	setContours(inputImg);

	for (int i = 0; i < contours.size(); i++){
		if (contourArea(contours[i]) > minArea)	//if the contour area is bigger than the minimum area
			rect = boundingRect(contours[i]);	//set the bounding box for the contour
		
		//setting the corners for the bounding rectangle
		pt1.x = rect.x;
		pt1.y = rect.y;
		pt2.x = rect.x + rect.width;
		pt2.y = rect.y + rect.height;

		//finding center of rectangle
		center.x = rect.x + rect.width / 2;
		center.y = rect.y + rect.height / 2;

		rectangle(result, pt1, pt2, CV_RGB(255, 0, 0), 1);	//drawing the rectangle
		line(result, center, center, Scalar(0,255,0), 2);	//drawing the center
	}

	return result;
}

Mat Bounder::rotatedBoundingBox(int minArea){
	Mat result = Mat::zeros(inputImg.rows, inputImg.cols,CV_8UC3);

	setContours(inputImg);

	Point2f vertices[4];	//holds the (x,y) of the four corners of the rotated rectangle

	for (int i = 0; i < contours.size(); i++){

		rRect = minAreaRect(contours[i]);		//setting the rRect as the smallest rect possible around the given contour

		rRect.points(vertices);					//setting the corners of the rRect

		for (int i = 0; i < 4; ++i)
			line(result, vertices[i], vertices[(i + 1) % 4], cv::Scalar(255, 0, 0), 1, CV_AA);	//drawing rRect
	}

	return result;
}
