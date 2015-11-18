#include "Recognizer.h"

//When declaring a recognizer, tell it which detector to use (a.k.a. which thresholdImages to use)
Recognizer::Recognizer(Detector d){
	dt = d;
}

Mat Recognizer::getBlueBLOBImg(){
	return blueBLOBImg;
}
Mat Recognizer::getGreenBLOBImg(){
	return greenBLOBImg;
}
Mat Recognizer::getRedBLOBImg(){
	return redBLOBImg;
}
Mat Recognizer::getYellowBLOBImg(){
	return yellowBLOBImg;
}

Detector Recognizer::getDetector(){
	return dt;
}
void Recognizer::setDetector(Detector d){
	dt = d;
}

//BLOB analyzes the relevant threshimages based on the char input.
void Recognizer::BLOBAnalyze(char letter) {
	switch (letter) {
	case 'a':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'b':
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'f':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		greenBLOBImg = BLOBdt.BLOBDetection(dt.getGreenThreshImg(), 'g');
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'l':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 's':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 't':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	default:
		cout << "ERROR: Recognizer has not been parsed a valid char in BLOBAnalyze." << endl;
		break;
	}
}

//TODO
void Recognizer::extractFeatures(char letter){
	switch (letter){
	case 'a':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows);
		yellowSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows);
		blueLargestX = Point(0,0);
		blueLargestX = Point(0,0);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX.x){
					blueSmallestX = blueBLOBList[i][j];
					//cout << "smallestX: " << smallestX << " | Point-x: " << blueBLOBList[i][j].x << " | Point-y: " << blueBLOBList[i][j].y << endl;
				}
				if (blueBLOBList[i][j].x > blueLargestX.x){
					blueLargestX = blueBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX.x){
					yellowSmallestX = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].x > yellowLargestX.x){
					yellowLargestX = yellowBLOBList[i][j];
				}
			}
		}

		break;
	case 'b':
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		redSmallestX = Point(redBLOBImg.cols, redBLOBImg.rows);
		redLargestX = Point(0,0);
		redLargestY = Point(0,0);
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows);
		yellowLargestX = Point(0,0);
		yellowSmallestY = Point(yellowBLOBImg.cols, yellowBLOBImg.rows);
		yellowLargestY = Point(0,0);

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
				if (redBLOBList[i][j].x < redSmallestX.x){
					redSmallestX = redBLOBList[i][j];
				}
				if (redBLOBList[i][j].x > redLargestX.x){
					redLargestX = redBLOBList[i][j];
				}
				if (redBLOBList[i][j].y > redLargestY.y){
					redLargestY = redBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX.x){
					yellowSmallestX = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].x > yellowLargestX.x){
					yellowLargestX = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY.y){
					yellowSmallestY = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].y > yellowLargestY.y){
					yellowLargestY = yellowBLOBList[i][j];
				}
			}
		}

		yellowCenter = Point(yellowSmallestX.x + (yellowLargestX.x-yellowSmallestX.x)/2, yellowSmallestY.y + (yellowLargestY.y-yellowSmallestY.y)/2);

		break;
	case 'f':
		blueBLOBList = BLOBdt.getBLOBList('b');
		greenBLOBList = BLOBdt.getBLOBList('g');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 'l':
		blueBLOBList = BLOBdt.getBLOBList('b');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 's':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 't':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	}
}

//TODO
bool Recognizer::compareFeatures(char letter){
	bool letterFound = false;
	hasBeenFound = Mat::zeros(50,50, CV_8UC3);

	switch (letter){
	case 'a':
		if (blueLargestX.x <= yellowSmallestX.x && (yellowSmallestX.x - blueLargestX.x) <= 50)
			letterFound = true;
		break;
	case 'b':
		redDistanceX = redLargestX.x - redSmallestX.x;
		if (yellowCenter.x < redLargestX.x-redDistanceX/4 && yellowCenter.x > redSmallestX.x+redDistanceX/4)
			letterFound = true;
		break;
	/*case 'f':
		if ()
			letterFound = true;
		break;
	case 'l':
		if ()
			letterFound = true;
		break;
	case 's':
		if ()
			letterFound = true;
		break;
	case 't':
		if ()
			letterFound = true;
		break;*/
	default:
		cout << "compareFeatures has not been parsed a valid char." << endl;
	}

	Point center;
	center.x = hasBeenFound.cols / 2;
	center.y = hasBeenFound.rows / 2;

	Scalar color;
	if (letterFound)
		color = CV_RGB(0, 255, 0);
	else
		color = CV_RGB(255, 0, 0);

	line(hasBeenFound, center, center, color, 6);
	imshow("Found", hasBeenFound);

	return letterFound;
}

//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
bool Recognizer::recognize(char letter){
	BLOBAnalyze(letter);
	extractFeatures(letter);
	
	return compareFeatures(letter);
}