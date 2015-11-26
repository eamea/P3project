#include "Recognizer.h"

//When declaring a recognizer, tell it which detector to use (a.k.a. which thresholdImages to use)
Recognizer::Recognizer(Detector d){
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

void Recognizer::compareFeatures(char letter, bool leftHand){
	letterFound = false;
	hasBeenFound = Mat::zeros(50,50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			if (blueLargestX > yellowSmallestX)
				cout << "Your thumb has to be on the right side of your index finger" << endl;
			if ((yellowSmallestX - blueLargestX) > 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (blueLargestX <= yellowSmallestX && (yellowSmallestX - blueLargestX) <= 50)
				letterFound = true;
			break;
		case 'b':
			redDistanceX = redLargestX - redSmallestX;
			if (yellowCenter.x > redLargestX - redDistanceX / 4)
				cout << "move your thumb to the other side of the index finger" << endl;
			if (yellowCenter.x < redSmallestX + redDistanceX / 4)
				cout << "how did you do this? O.O" << endl;
			if (yellowCenter.x < redLargestX - redDistanceX / 4 && yellowCenter.x > redSmallestX + redDistanceX / 4)
				letterFound = true;
			break;
		case 'f':
			if (yellowSmallestY > blueLargestY)
				cout << "your thumb has to be below your index finger" << endl;
			if (yellowLargestX > blueLargestX + 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowLargestX < blueLargestX - 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowSmallestY < redLargestY)
				cout << "strecth out your middle, ring and little finger" << endl;
			if (redLargestX > blueLargestX)
				cout << "your index finger has to be below your little finger" << endl;
			if (redBLOBList.size() < 3)
				cout << "make sure all your fingers are visible in the image" << endl;
			if (yellowSmallestY > blueLargestY && (yellowLargestX < blueLargestX + 50 && yellowLargestX > blueLargestX - 50) && yellowSmallestY > redLargestY && redLargestX < blueLargestX && redBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 'l':
			if (blueLargestX > redLargestX)
				cout << "move your index finger more to your right" << endl;
			if (redLargestX > yellowSmallestX)
				cout << "strecth your thumb" << endl;
			if (yellowSmallestY < blueSmallestY)
				cout << "strecth your thumb" << endl;
			if (blueBLOBList.size() < 4)
				cout << "make sure all your finger are visible in the image" << endl;
			if (redBLOBList.size() < 2)
				cout << "make sure all your finger are visible in the image" << endl;
			if (blueLargestX < redLargestX && redLargestX < yellowSmallestX && yellowSmallestY > blueSmallestY && blueBLOBList.size() >= 4 && redBLOBList.size() >= 2)
				letterFound = true;
			break;
		case 's':
			if (yellowLargestX > blueLargestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (yellowSmallestY < blueSmallestY)
				cout << "move your thumb down" << endl;
			if (yellowSmallestY > blueLargestY)
				cout << "move your thumb up" << endl;
			if (blueBLOBList.size() < 3)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestX < blueLargestX && yellowSmallestY > blueSmallestY && yellowSmallestY < blueLargestY && blueBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 't':
			if (yellowLargestY > blueLargestY)
				cout << "move your thumb up a bit" << endl;
			if (yellowCenter.x < blueSmallestX + 3 * (blueDistanceX / 4) - 10)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (yellowCenter.x > blueLargestX)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (blueBLOBList.size() < 5)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestY < blueLargestY && yellowCenter.x > blueSmallestX + 3 * (blueDistanceX / 4) - 10 && yellowCenter.x < blueLargestX && blueBLOBList.size() >= 5)
				letterFound = true;
			break;
		default:
			cout << "compareFeatures has not been parsed a valid char." << endl;
		}
	}
	else{
		switch (letter){
		case 'a':
			if (blueLargestX < yellowSmallestX)
				cout << "Your thumb has to be on the left side of your index finger" << endl;
			if ((blueSmallestX - yellowLargestX) > 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (blueSmallestX >= yellowLargestX && (blueSmallestX - yellowLargestX) <= 50)
				letterFound = true;
			break;
		case 'b':
			redDistanceX = redLargestX - redSmallestX;
			if (yellowCenter.x > redLargestX - redDistanceX / 4)
				cout << "How did you do this? o.O" << endl;
			if (yellowCenter.x < redSmallestX + redDistanceX / 4)
				cout << "move your thumb to the other side of your index finger" << endl;
			if (yellowCenter.x < redLargestX - redDistanceX / 4 && yellowCenter.x > redSmallestX + redDistanceX / 4)
				letterFound = true;
			break;
		case 'f':
			if (yellowSmallestY > blueLargestY)
				cout << "your thumb has to be below your index finger" << endl;
			if (yellowLargestX > blueLargestX + 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowLargestX < blueLargestX - 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowSmallestY < redLargestY)
				cout << "strecth out your middle, ring and little finger" << endl;
			if (redSmallestX < blueLargestX)
				cout << "your index finger has to be left of your ring finger" << endl;
			if (redBLOBList.size() < 3)
				cout << "make sure all your fingers are visible in the image" << endl;
			if (yellowSmallestY > blueLargestY && (yellowLargestX < blueLargestX + 50 && yellowLargestX > blueLargestX - 50) && yellowSmallestY > redLargestY && redSmallestX > blueLargestX && redBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 'l':
			if (blueSmallestX < redSmallestX)
				cout << "move your index finger more to your left" << endl;
			if (redSmallestX < yellowLargestX)
				cout << "strecth your thumb" << endl;
			if (yellowSmallestY < blueSmallestY)
				cout << "strecth your thumb" << endl;
			if (blueBLOBList.size() < 4)
				cout << "make sure all your finger are visible in the image" << endl;
			if (redBLOBList.size() < 2)
				cout << "make sure all your finger are visible in the image" << endl;
			if (blueSmallestX > redSmallestX && redSmallestX > yellowLargestX && yellowSmallestY > blueSmallestY && blueBLOBList.size() >= 4 && redBLOBList.size() >= 2)
				letterFound = true;
			break;
		case 's':
			if (yellowLargestX > blueLargestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (yellowSmallestY < blueSmallestY)
				cout << "move your thumb down" << endl;
			if (yellowSmallestY > blueLargestY)
				cout << "move your thumb up" << endl;
			if (blueBLOBList.size() < 3)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestX < blueLargestX && yellowSmallestY > blueSmallestY && yellowSmallestY < blueLargestY && blueBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 't':
			if (yellowLargestY > blueLargestY)
				cout << "move your thumb up a bit" << endl;
			if (yellowCenter.x > blueLargestX - 2 * (blueDistanceX / 4) + 10)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (yellowCenter.x < blueSmallestX)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (blueBLOBList.size() < 5)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestY < blueLargestY && yellowCenter.x < blueLargestX - 2 * (blueDistanceX / 4) + 10 && yellowCenter.x > blueSmallestX && blueBLOBList.size() >= 5)
				letterFound = true;
			break;
		default:
			cout << "compareFeatures has not been parsed a valid char." << endl;
		}
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

void Recognizer::compareFeaturesGlove2(char letter, bool leftHand){
	letterFound = false;
	hasBeenFound = Mat::zeros(50, 50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x || greenCenter.x > redCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowCenter.y < blueCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowCenter.y > blueCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (blueCenter.y < pinkCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (blueCenter.y > pinkCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkCenter.y < greenCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkCenter.y > greenCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (greenCenter.y < yellowCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (greenCenter.y > yellowCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x && greenCenter.x < redCenter.x /*if the fingers are in the right succession*/
				&& yellowCenter.y > blueCenter.y - multiplier2*errorAllowance && yellowCenter.y < blueCenter.y + multiplier2*errorAllowance
				&& blueCenter.y > pinkCenter.y - multiplier2*errorAllowance && blueCenter.y < pinkCenter.y + multiplier2*errorAllowance
				&& pinkCenter.y > greenCenter.y - multiplier2*errorAllowance && pinkCenter.y < pinkCenter.y + multiplier2*errorAllowance
				&& greenCenter.y > redCenter.y - multiplier2*errorAllowance && greenCenter.y < redCenter.y + multiplier2*errorAllowance /*and their y-centers are the same, +-20 pixels*/){
				letterFound = true;
			}
			break;
		case 'b':
			if (redCenter.y < yellowCenter.y)
				cout << "make sure your thumb is below your little finger" << endl; 
			if (redCenter.x < yellowCenter.x)
				cout << "how di you do this o.O" << endl;
			if (redCenter.x > greenCenter.x)
				cout << "move your thumb to the other side of you index finger" << endl;

			if (redCenter.y > yellowCenter.y && redCenter.x > yellowCenter.x && redCenter.x < greenCenter.x)
				letterFound = true;
			break;
		case 'f':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (greenLargestY < redSmallestY - errorAllowance)
				cout << "make sure your tumb is below your index finger" << endl;
			if (greenLargestY > redSmallestY + errorAllowance)
				cout << "move your thumb closer to your index finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& greenLargestY > redSmallestY - errorAllowance && greenLargestY < redSmallestY + errorAllowance)
				letterFound = true;
			break;
		case 'l':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x || greenCenter.x > redCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (redCenter.y < pinkCenter.y)
				cout << "stretch out your thumb" << endl;
			if (greenCenter.y > pinkCenter.y)
				cout << "stretch out your index finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x && greenCenter.x < redCenter.x /*if the fingers are in the right succession*/
				&& redCenter.y > pinkCenter.y && greenCenter.y < pinkCenter.y)
				letterFound = true;
			break;
		case 's':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY < blueSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY > blueSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY < pinkSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY > pinkSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY < greenSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY > greenSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x > greenLargestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (redCenter.x < pinkSmallestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (greenCenter.y > yellowCenter.y)
				cout << "move your thumb in front of your index finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY > blueSmallestY - errorAllowance*multiplier && yellowSmallestY < blueSmallestY + errorAllowance*multiplier
				&& blueSmallestY > pinkSmallestY - errorAllowance*multiplier && blueSmallestY < pinkSmallestY + errorAllowance*multiplier
				&& pinkSmallestY > greenSmallestY - errorAllowance*multiplier && pinkSmallestY < greenSmallestY + errorAllowance*multiplier
				&& redCenter.x < greenLargestX && redCenter.x > pinkSmallestX
				&& greenCenter.y < yellowCenter.y)
				letterFound = true;
			break;
		case 't':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY < blueSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY > blueSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY < pinkSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY > pinkSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY < greenSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY > greenSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x > greenLargestX || redCenter.x < pinkSmallestX)
				cout << "move your thumb between your index and middle finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY > blueSmallestY - errorAllowance*multiplier && yellowSmallestY < blueSmallestY + errorAllowance*multiplier
				&& blueSmallestY > pinkSmallestY - errorAllowance*multiplier && blueSmallestY < pinkSmallestY + errorAllowance*multiplier
				&& pinkSmallestY > greenSmallestY - errorAllowance*multiplier && pinkSmallestY < greenSmallestY + errorAllowance*multiplier
				&& redCenter.x < greenLargestX && redCenter.x > pinkSmallestX)
				letterFound = true;
			break;
		default:
			cout << "compareFeatures has not been parsed a valid char." << endl;
		}
	}
	else{
		switch (letter){
		case 'a':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x || greenCenter.x < redCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowCenter.y < blueCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowCenter.y > blueCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (blueCenter.y < pinkCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (blueCenter.y > pinkCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkCenter.y < greenCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkCenter.y > greenCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (greenCenter.y < yellowCenter.y - multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;
			if (greenCenter.y > yellowCenter.y + multiplier2*errorAllowance)
				cout << "make sure your fingers are alligned" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x && greenCenter.x > redCenter.x /*if the fingers are in the right succession*/
				&& yellowCenter.y > blueCenter.y - multiplier2*errorAllowance && yellowCenter.y < blueCenter.y + multiplier2*errorAllowance
				&& blueCenter.y > pinkCenter.y - multiplier2*errorAllowance && blueCenter.y < pinkCenter.y + multiplier2*errorAllowance
				&& pinkCenter.y > greenCenter.y - multiplier2*errorAllowance && pinkCenter.y < pinkCenter.y + multiplier2*errorAllowance
				&& greenCenter.y > redCenter.y - multiplier2*errorAllowance && greenCenter.y < redCenter.y + multiplier2*errorAllowance /*and their y-centers are the same, +-20 pixels*/){
				letterFound = true;
			}
			break;
		case 'b':
			if (redCenter.y < yellowCenter.y)
				cout << "make sure your thumb is below your little finger" << endl;
			if (redCenter.x > yellowCenter.x)
				cout << "how did you do this o.O" << endl;
			if (redCenter.x < greenCenter.x)
				cout << "move your thumb to the other side of you index finger" << endl;

			if (redCenter.y > yellowCenter.y && redCenter.x < yellowCenter.x && redCenter.x > greenCenter.x)
				letterFound = true;
			break;
		case 'f':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (greenLargestY < redSmallestY - errorAllowance)
				cout << "make sure your tumb is below your index finger" << endl;
			if (greenLargestY > redSmallestY + errorAllowance)
				cout << "move your thumb closer to your index finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& greenLargestY > redSmallestY - errorAllowance && greenLargestY < redSmallestY + errorAllowance)
				letterFound = true;
			break;
		case 'l':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x || greenCenter.x < redCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (redCenter.y < pinkCenter.y)
				cout << "stretch out your thumb" << endl;
			if (greenCenter.y > pinkCenter.y)
				cout << "stretch out your index finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x && greenCenter.x > redCenter.x /*if the fingers are in the right succession*/
				&& redCenter.y > pinkCenter.y && greenCenter.y < pinkCenter.y)
				letterFound = true;
			break;
		case 's':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY < blueSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY > blueSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY < pinkSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY > pinkSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY < greenSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY > greenSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x < greenSmallestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (redCenter.x > pinkLargestX)
				cout << "move your thumb in front of your index finger" << endl;
			if (greenCenter.y > yellowCenter.y)
				cout << "move your thumb in front of your index finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY > blueSmallestY - errorAllowance*multiplier && yellowSmallestY < blueSmallestY + errorAllowance*multiplier
				&& blueSmallestY > pinkSmallestY - errorAllowance*multiplier && blueSmallestY < pinkSmallestY + errorAllowance*multiplier
				&& pinkSmallestY > greenSmallestY - errorAllowance*multiplier && pinkSmallestY < greenSmallestY + errorAllowance*multiplier
				&& redCenter.x > greenSmallestX && redCenter.x < pinkLargestX
				&& greenCenter.y < yellowCenter.y)
				letterFound = true;
			break;
		case 't':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY < blueSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY > blueSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY < pinkSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY > pinkSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY < greenSmallestY - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY > greenSmallestY + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x < greenSmallestX || redCenter.x > pinkLargestX)
				cout << "move your thumb between your index and middle finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY > blueSmallestY - errorAllowance*multiplier && yellowSmallestY < blueSmallestY + errorAllowance*multiplier
				&& blueSmallestY > pinkSmallestY - errorAllowance*multiplier && blueSmallestY < pinkSmallestY + errorAllowance*multiplier
				&& pinkSmallestY > greenSmallestY - errorAllowance*multiplier && pinkSmallestY < greenSmallestY + errorAllowance*multiplier
				&& redCenter.x > greenSmallestX && redCenter.x < pinkLargestX)
				letterFound = true;
			break;
		default:
			cout << "compareFeatures has not been parsed a valid char." << endl;
		}
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
}

void Recognizer::extractFeaturesVector(){
	blueBLOBList.resize(0);
	greenBLOBList.resize(0);
	pinkBLOBList.resize(0);
	redBLOBList.resize(0);
	yellowBLOBList.resize(0);

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

	lengthYelBlue = 0;

	for (int i = 0; i < blueBLOBList.size(); i++){
		for (int j = 1; j < blueBLOBList[i].size(); j++){
			if (blueBLOBList[i][j].x < blueSmallestX){
				blueSmallestXPoint = blueBLOBList[i][j];
				blueSmallestX = blueBLOBList[i][j].x;
			}
			if (blueBLOBList[i][j].x > blueLargestX){
				blueLargestXPoint = blueBLOBList[i][j];
				blueLargestX = blueBLOBList[i][j].x;
			}
			if (blueBLOBList[i][j].y < blueSmallestY){
				blueSmallestYPoint = blueBLOBList[i][j];
				blueSmallestY = blueBLOBList[i][j].y;
			}
			if (blueBLOBList[i][j].y > blueLargestY){
				blueLargestY = blueBLOBList[i][j].y;
				blueLargestYPoint = blueBLOBList[i][j];
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
				redLargestPoint = redBLOBList[i][j];
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
				yellowLargestXPoint = yellowBLOBList[i][j];
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

	lengthYelBlue = yellowSmallestX - blueLargestX;
}

void Recognizer::vectorRecognizer(char letter, bool leftHand){
	BLOBAnalyze(letter);
	extractFeaturesVector();

	letterFound = false;
	hasBeenFound = Mat::zeros(50, 50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			currentSign.push_back((float) lengthYelBlue);
			currentSign.push_back((float) blueBLOBList.size());
			
			idealSign.push_back (7);
			idealSign.push_back(4);
			
			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f) + pow(idealSign[1] - currentSign[1], 2.0f));

			cout << "length : " << currentSign[0] << ", Number of BLOBS: " << currentSign[1] << endl;
			cout << "euclidian distance: " << euclidianDistance << endl;

			if (euclidianDistance < 5 && blueBLOBList.size() >= 4)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'b':
			if (yellowCenter.x < redLargestX - redDistanceX / 4 && yellowCenter.x > redSmallestX + redDistanceX / 4)
				currentSign.push_back(1);
			else
				currentSign.push_back(0);

			idealSign.push_back(1);

			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << euclidianDistance << endl;

			if (euclidianDistance < 1)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);
				
			break;
		case 'f':
			lengthYelBlue = sqrt(pow(blueLargestYPoint.x - yellowCenter.x, 2.0f) + pow(blueLargestYPoint.y - yellowCenter.y, 2.0f));
			lengthYelRed = sqrt(pow(redLargestPoint.x - yellowCenter.x, 2.0f) + pow(redLargestPoint.y - yellowCenter.y, 2.0f));

			ratio = (float)lengthYelBlue / (float)lengthYelRed;

			currentSign.push_back(ratio);
			idealSign.push_back(0.3f);

			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclidianDistance << endl;

			if (euclidianDistance < 0.09f)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);
			idealSign.empty();
			idealSign.resize(0);
			lengthYelBlue = 0;
			lengthYelRed = 0;
			ratio = 0;

			break;
		case 'l':
			//length between yellow center and red center
			//distance between blue cebter and red center

			lengthYelRed = sqrt(pow(redCenter.x - yellowCenter.x, 2.0f) + pow(redCenter.y - yellowCenter.y, 2.0f));
			lengthBlueRed = sqrt(pow(redCenter.x - blueSmallestXPoint.x, 2.0f) + pow(redCenter.y - blueSmallestXPoint.y, 2.0f));

			ratio = lengthYelRed / lengthBlueRed;

			currentSign.push_back(ratio);
			idealSign.push_back(1.0f);

			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclidianDistance < 0.5f)
				letterFound = true;

			cout << euclidianDistance << endl;
			
			currentSign.empty();
			currentSign.resize(0);
			idealSign.empty();
			idealSign.resize(0);
			ratio = 0;
			lengthYelRed = 0;
			lengthBlueRed = 0;

			break;
		case 's':
			//length between yellowMinX and blueMinX
			//length between yellowMinY and blueMinY

			lengthYelBlue = sqrt(pow(yellowCenter.x - blueSmallestXPoint.x, 2.0f) + pow(yellowCenter.y - blueSmallestXPoint.y, 2.0f));
			//lengthBlueYel = sqrt(pow(yellowLargestXPoint.x - blueSmallestXPoint.x, 2.0f) + pow(yellowLargestXPoint.y - blueSmallestXPoint.y, 2.0f));

			blueSmallestYPoint.x = yellowCenter.x;
			blueLargestYPoint.x = yellowCenter.x;

			lengthBlue = sqrt(pow(yellowCenter.x - blueCenter.x, 2.0f) + pow(yellowCenter.y - blueCenter.y, 2.0f));

			//lengthBlueYel = sqrt(pow(yellowCenter.x - blueCenter.x, 2.0f) + pow(yellowCenter.y - blueCenter.y, 2.0f));

			ratio = lengthYelBlue / lengthBlue;

			currentSign.push_back(ratio);
			idealSign.push_back(1.6f);

			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclidianDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclidianDistance << endl;

			currentSign.empty();
			currentSign.resize(0);
			idealSign.empty();
			idealSign.resize(0);
			ratio = 0;
			lengthYelBlue = 0;
			lengthBlueYel = 0;
			euclidianDistance = 0;

			break;
		case 't':
			//ratio between yellowCenter/blueLargestX and yellowCenter/blueSmallestX

			yellowCenter.y = blueSmallestXPoint.y;
			blueLargestXPoint.y = blueSmallestXPoint.y;

			lengthYelBlue = sqrt(pow(yellowCenter.x - blueSmallestXPoint.x, 2.0f) + pow(yellowCenter.y - blueSmallestXPoint.y, 2.0f));
			lengthBlueYel = sqrt(pow(yellowCenter.x - blueLargestXPoint.x, 2.0f) + pow(yellowCenter.y - blueLargestXPoint.y, 2.0f));

			ratio = lengthYelBlue / lengthBlueYel;

			currentSign.push_back(ratio);
			idealSign.push_back(3.7f);

			euclidianDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclidianDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclidianDistance << endl;

			currentSign.empty();
			currentSign.resize(0);
			idealSign.empty();
			idealSign.resize(0);
			ratio = 0;
			lengthYelBlue = 0;
			lengthBlueYel = 0;
			euclidianDistance = 0;

			break;
		default:
			cout << "vectorRecognizer was not passed a valid letter" << endl;
		}
	}
	else{
		switch (letter){
		case 'a':
			break;
		case 'b':
			break;
		case 'f':
			break;
		case 'l':
			break;
		case 's':
			break;
		case 't':
			break;
		default:
			cout << "vectorRecognizer was not passed a valid letter" << endl;
		}
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
}

vector<float> Recognizer::normalizeValues(vector<float> vc){
	float min = vc[0];
	float max = vc[0];

	for (int i = 0; i < vc.size(); i++){
		if (vc[i] > max){
			max = vc[i];
		}
		if (vc[i] < min){
			min = vc[i];
		}
	}

	for (size_t i = 0; i < vc.size(); i++){
		vc[i] = (vc[i] - min) / (max - min);
	}

	cout << "Normalised vector: " << vc[0] << " : " << vc[1] << endl;

	return vc;
}

//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
void Recognizer::recognize(char letter, bool leftHand){
	BLOBAnalyze(letter);
	extractFeatures(letter);
	
	compareFeatures(letter, leftHand);
}

void Recognizer::recognizeGlove2(char letter, bool leftHand){
	BLOBAnalyzeGlove2();
	extractFeaturesGlove2();

	compareFeaturesGlove2(letter, leftHand);
}

bool Recognizer::getLetterFound(){
	return letterFound;
}
float Recognizer::getEuclideanDistance(){
	return euclidianDistance;
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