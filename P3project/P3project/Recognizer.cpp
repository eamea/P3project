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
Mat Recognizer::getPinkBLOBImg(){
	return pinkBLOBImg;
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

void Recognizer::BLOBAnalyzeGlove2(){
	blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
	greenBLOBImg = BLOBdt.BLOBDetection(dt.getGreenThreshImg(), 'g');
	pinkBLOBImg = BLOBdt.BLOBDetection(dt.getPinkThreshImg(), 'p');
	redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
	yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
}

void Recognizer::extractFeatures(char letter){
	switch (letter){
	case 'a':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = blueBLOBImg.cols;
		yellowSmallestX = yellowBLOBImg.cols;
		blueLargestX = 0;
		blueLargestX = 0;

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX){
					blueSmallestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].x > blueLargestX){
					blueLargestX = blueBLOBList[i][j].x;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX){
					yellowSmallestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].x > yellowLargestX){
					yellowLargestX = yellowBLOBList[i][j].x;
				}
			}
		}

		break;
	case 'b':
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		redSmallestX = redBLOBImg.cols;
		redLargestX = 0;
		redLargestY = 0;
		yellowSmallestX = yellowBLOBImg.cols;
		yellowLargestX = 0;
		yellowSmallestY = yellowBLOBImg.rows;
		yellowLargestY = 0;

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
				if (redBLOBList[i][j].x < redSmallestX){
					redSmallestX = redBLOBList[i][j].x;
				}
				if (redBLOBList[i][j].x > redLargestX){
					redLargestX = redBLOBList[i][j].x;
				}
				if (redBLOBList[i][j].y > redLargestY){
					redLargestY = redBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX){
					yellowSmallestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].x > yellowLargestX){
					yellowLargestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY){
					yellowSmallestY = yellowBLOBList[i][j].y;
				}
				if (yellowBLOBList[i][j].y > yellowLargestY){
					yellowLargestY = yellowBLOBList[i][j].y;
				}
			}
		}

		yellowCenter = Point(yellowSmallestX + (yellowLargestX-yellowSmallestX)/2, yellowSmallestY + (yellowLargestY-yellowSmallestY)/2);

		break;
	case 'f':
		blueBLOBList = BLOBdt.getBLOBList('b');
		greenBLOBList = BLOBdt.getBLOBList('g');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = blueBLOBImg.cols;
		blueLargestX = 0;
		blueLargestY = 0;
		redLargestX = 0;
		redLargestY = 0;
		yellowSmallestX = yellowBLOBImg.cols;
		yellowLargestX = 0;
		yellowSmallestY = yellowBLOBImg.rows;

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX){
					blueSmallestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].x > blueLargestX){
					blueLargestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].y > blueLargestY){
					blueLargestY = blueBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
				if (redBLOBList[i][j].x > redLargestX){
					redLargestX = redBLOBList[i][j].x;
				}
				if (redBLOBList[i][j].y > redLargestY){
					redLargestY = redBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX){
					yellowSmallestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].x > yellowLargestX){
					yellowLargestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY){
					yellowSmallestY = yellowBLOBList[i][j].y;
				}
			}
		}
		

		break;
	case 'l':
		blueBLOBList = BLOBdt.getBLOBList('b');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueLargestX = 0;
		blueSmallestY = blueBLOBImg.rows;
		redLargestX = 0;
		yellowSmallestX = yellowBLOBImg.cols;
		yellowSmallestY = yellowBLOBImg.rows;

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x > blueLargestX){
					blueLargestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].y < blueSmallestY){
					blueSmallestY = blueBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
				if (redBLOBList[i][j].x > redLargestX){
					redLargestX = redBLOBList[i][j].x;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX){
					yellowSmallestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY){
					yellowSmallestY = yellowBLOBList[i][j].y;
				}
			}
		}

		break;
	case 's':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueLargestX = 0;
		blueSmallestY = blueBLOBImg.rows;
		blueLargestY = 0;
		yellowLargestX = 0;
		yellowSmallestY = yellowBLOBImg.rows;

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x > blueLargestX){
					blueLargestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].y < blueSmallestY){
					blueSmallestY = blueBLOBList[i][j].y;
				}
				if (blueBLOBList[i][j].y > blueLargestY){
					blueLargestY = blueBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x > yellowLargestX){
					yellowLargestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY){
					yellowSmallestY = yellowBLOBList[i][j].y;
				}
			}
		}

		break;
	case 't':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = blueBLOBImg.cols;
		blueLargestX = 0;
		blueLargestY = 0;
		blueDistanceX = blueLargestX - blueSmallestX;
		yellowSmallestX = yellowBLOBImg.cols;
		yellowLargestX = 0;
		yellowSmallestY = yellowBLOBImg.rows;
		yellowLargestY = 0;

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX){
					blueSmallestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].x > blueLargestX){
					blueLargestX = blueBLOBList[i][j].x;
				}
				if (blueBLOBList[i][j].y > blueLargestY){
					blueLargestY = blueBLOBList[i][j].y;
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX){
					yellowSmallestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].x > yellowLargestX){
					yellowLargestX = yellowBLOBList[i][j].x;
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY){
					yellowSmallestY = yellowBLOBList[i][j].y;
				}
				if (yellowBLOBList[i][j].y > yellowLargestY){
					yellowLargestY = yellowBLOBList[i][j].y;
				}
			}
		}

		yellowCenter = Point(yellowSmallestX + (yellowLargestX - yellowSmallestX) / 2, yellowSmallestY + (yellowLargestY - yellowSmallestY) / 2);

		break;
	}
}

bool Recognizer::compareFeatures(char letter){
	bool letterFound = false;
	hasBeenFound = Mat::zeros(50,50, CV_8UC3);

	switch (letter){
	case 'a':
		if (blueLargestX <= yellowSmallestX && (yellowSmallestX - blueLargestX) <= 50)
			letterFound = true;
		break;
	case 'b':
		redDistanceX = redLargestX - redSmallestX;
		if (yellowCenter.x < redLargestX-redDistanceX/4 && yellowCenter.x > redSmallestX+redDistanceX/4)
			letterFound = true;
		break;
	case 'f':
		if (yellowSmallestY > blueLargestY && (yellowLargestX < blueLargestX + 50 && yellowLargestX > blueLargestX  - 50) && yellowSmallestY > redLargestY && redLargestX < blueLargestX && redBLOBList.size() >= 3)
			letterFound = true;
		break;
	case 'l':
		if (blueLargestX < redLargestX && redLargestX < yellowSmallestX && yellowSmallestY > blueSmallestY && blueBLOBList.size() >= 4 && redBLOBList.size() >= 2)
			letterFound = true;
		break;
	case 's':
		if (yellowLargestX < blueLargestX && yellowSmallestY > blueSmallestY && yellowSmallestY < blueLargestY && blueBLOBList.size() >= 3)
			letterFound = true;
		break;
	case 't':
		if (yellowLargestY < blueLargestY && yellowCenter.x > blueSmallestX + 3*(blueDistanceX/4) - 10 && yellowCenter.x < blueLargestX && blueBLOBList.size() >= 5)
			letterFound = true;
		break;
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

void Recognizer::extractFeaturesGlove2(){
	blueBLOBList = BLOBdt.getBLOBList('b');
	greenBLOBList = BLOBdt.getBLOBList('g');
	pinkBLOBList = BLOBdt.getBLOBList('p');
	redBLOBList = BLOBdt.getBLOBList('r');
	yellowBLOBList = BLOBdt.getBLOBList('y');

	blueSmallestX = blueBLOBImg.cols;
	blueSmallestY = blueBLOBImg.rows;
	greenSmallestX = greenBLOBImg.cols;
	greenSmallestY = greenBLOBImg.rows;
	pinkSmallestX = pinkBLOBImg.cols;
	pinkSmallestY = pinkBLOBImg.rows;
	redSmallestX = redBLOBImg.cols;
	redSmallestY = redBLOBImg.rows;
	yellowSmallestX = yellowBLOBImg.cols;
	yellowSmallestY = yellowBLOBImg.rows;

	blueLargestX = 0;
	blueLargestY = 0;
	greenLargestX = 0;
	greenLargestY = 0;
	pinkLargestX = 0;
	pinkLargestY = 0;
	redLargestX = 0;
	redLargestY = 0;
	yellowLargestX = 0;
	yellowLargestY = 0;

	for (int i = 0; i < blueBLOBList.size(); i++){
		for (int j = 1; j < blueBLOBList[i].size(); j++){
			if (blueBLOBList[i][j].x < blueSmallestX){
				blueSmallestX = blueBLOBList[i][j].x;
			}
			if (blueBLOBList[i][j].x > blueLargestX){
				blueLargestX = blueBLOBList[i][j].x;
			}
			if (blueBLOBList[i][j].y < blueSmallestY){
				blueSmallestY = blueBLOBList[i][j].y;
			}
			if (blueBLOBList[i][j].y > blueLargestY){
				blueLargestY = blueBLOBList[i][j].y;
			}
		}
	}

	blueCenter = Point(blueSmallestX + (blueLargestX - blueSmallestX) / 2, blueSmallestY + (blueLargestY - blueSmallestY) / 2);

	for (int i = 0; i < greenBLOBList.size(); i++){
		for (int j = 1; j < greenBLOBList[i].size(); j++){
			if (greenBLOBList[i][j].x < greenSmallestX){
				greenSmallestX = greenBLOBList[i][j].x;
			}
			if (greenBLOBList[i][j].x > greenLargestX){
				greenLargestX = greenBLOBList[i][j].x;
			}
			if (greenBLOBList[i][j].y < greenSmallestY){
				greenSmallestY = greenBLOBList[i][j].y;
			}
			if (greenBLOBList[i][j].y > greenLargestY){
				greenLargestY = greenBLOBList[i][j].y;
			}
		}
	}

	greenCenter = Point(greenSmallestX + (greenLargestX - greenSmallestX) / 2, greenSmallestY + (greenLargestY - greenSmallestY) / 2);

	for (int i = 0; i < pinkBLOBList.size(); i++){
		for (int j = 1; j < pinkBLOBList[i].size(); j++){
			if (pinkBLOBList[i][j].x < pinkSmallestX){
				pinkSmallestX = pinkBLOBList[i][j].x;
			}
			if (pinkBLOBList[i][j].x > pinkLargestX){
				pinkLargestX = pinkBLOBList[i][j].x;
			}
			if (pinkBLOBList[i][j].y < pinkSmallestY){
				pinkSmallestY = pinkBLOBList[i][j].y;
			}
			if (pinkBLOBList[i][j].y > pinkLargestY){
				pinkLargestY = pinkBLOBList[i][j].y;
			}
		}
	}

	pinkCenter = Point(pinkSmallestX + (pinkLargestX - pinkSmallestX) / 2, pinkSmallestY + (pinkLargestY - pinkSmallestY) / 2);

	for (int i = 0; i < redBLOBList.size(); i++){
		for (int j = 1; j < redBLOBList[i].size(); j++){
			if (redBLOBList[i][j].x < redSmallestX){
				redSmallestX = redBLOBList[i][j].x;
			}
			if (redBLOBList[i][j].x > redLargestX){
				redLargestX = redBLOBList[i][j].x;
			}
			if (redBLOBList[i][j].y < redSmallestY){
				redSmallestY = redBLOBList[i][j].y;
			}
			if (redBLOBList[i][j].y > redLargestY){
				redLargestY = redBLOBList[i][j].y;
			}
		}
	}

	redCenter = Point(redSmallestX + (redLargestX - redSmallestX) / 2, redSmallestY + (redLargestY - redSmallestY) / 2);

	for (int i = 0; i < yellowBLOBList.size(); i++){
		for (int j = 1; j < yellowBLOBList[i].size(); j++){
			if (yellowBLOBList[i][j].x < yellowSmallestX){
				yellowSmallestX = yellowBLOBList[i][j].x;
			}
			if (yellowBLOBList[i][j].x > yellowLargestX){
				yellowLargestX = yellowBLOBList[i][j].x;
			}
			if (yellowBLOBList[i][j].y < yellowSmallestY){
				yellowSmallestY = yellowBLOBList[i][j].y;
			}
			if (yellowBLOBList[i][j].y > yellowLargestY){
				yellowLargestY = yellowBLOBList[i][j].y;
			}
		}
	}

	yellowCenter = Point(yellowSmallestX + (yellowLargestX - yellowSmallestX) / 2, yellowSmallestY + (yellowLargestY - yellowSmallestY) / 2);
}

bool Recognizer::compareFeaturesGlove2(char letter){
	bool letterFound = false;
	hasBeenFound = Mat::zeros(50, 50, CV_8UC3);

	switch (letter){ //IMPLEMENTED FOR LEFT HAND ONLY SO FAR
	case 'a':
		if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x && greenCenter.x < redCenter.x /*if the fingers are in the right succession*/
			&& yellowCenter.y > blueCenter.y - errorAllowance && yellowCenter.y < blueCenter.y + errorAllowance
			&& blueCenter.y > pinkCenter.y - errorAllowance && blueCenter.y < pinkCenter.y + errorAllowance
			&& pinkCenter.y > greenCenter.y - errorAllowance && pinkCenter.y < pinkCenter.y + errorAllowance
			&& greenCenter.y > redCenter.y - errorAllowance && greenCenter.y < redCenter.y + errorAllowance /*and their y-centers are the same, +-20 pixels*/){
			letterFound = true;
		}
		break;
	case 'b':

	//NOT WORKING

		if (redCenter.y < yellowCenter.y && redCenter.x > yellowCenter.x && redCenter.x < greenCenter.x)
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

bool Recognizer::recognizeGlove2(char letter){
	BLOBAnalyzeGlove2();
	extractFeaturesGlove2();

	return compareFeaturesGlove2(letter);
}