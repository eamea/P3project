#include "Recognizer.h"

//when declaring a recognizer, tell it which detector to use (a.k.a. which thresholdImages to use)
Recognizer::Recognizer(Detector d){
	dt = d;
}

//BLOB analyzes the relevant threshimages based on the char input
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

		blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows / 2);
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
		blueLargestX = Point(0, blueBLOBImg.rows / 2);
		yellowLargestX = Point(0, yellowBLOBImg.rows / 2);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX.x){
					blueSmallestX = blueBLOBList[i][j];
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

		redSmallestX = Point(redBLOBImg.cols, redBLOBImg.rows / 2);
		redLargestX = Point(0, redBLOBImg.rows / 2);
		redLargestY = Point(redBLOBImg.cols / 2, 0);
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
		yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
		yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);
		yellowLargestY = Point(yellowBLOBImg.cols / 2, 0);

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

		yellowCenter = Point(yellowSmallestX.x + (yellowLargestX.x - yellowSmallestX.x) / 2, yellowSmallestY.y + (yellowLargestY.y - yellowSmallestY.y) / 2);

		break;
	case 'f':
		blueBLOBList = BLOBdt.getBLOBList('b');
		greenBLOBList = BLOBdt.getBLOBList('g');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows / 2);
		blueLargestX = Point(0, blueBLOBImg.rows / 2);
		blueLargestY = Point(blueBLOBImg.cols / 2, 0);
		redLargestX = Point(0, redBLOBImg.rows / 2);
		redLargestY = Point(redBLOBImg.cols / 2, 0);
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
		yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
		yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX.x){
					blueSmallestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].x > blueLargestX.x){
					blueLargestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].y > blueLargestY.y){
					blueLargestY = blueBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
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
			}
		}
		

		break;
	case 'l':
		blueBLOBList = BLOBdt.getBLOBList('b');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueLargestX = Point(0, blueBLOBImg.rows / 2);
		blueSmallestY = Point(blueBLOBImg.cols / 2, blueBLOBImg.rows);
		redLargestX = Point(0, redBLOBImg.rows / 2);
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
		yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x > blueLargestX.x){
					blueLargestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].y < blueSmallestY.y){
					blueSmallestY = blueBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < redBLOBList.size(); i++){
			for (int j = 1; j < redBLOBList[i].size(); j++){
				if (redBLOBList[i][j].x > redLargestX.x){
					redLargestX = redBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x < yellowSmallestX.x){
					yellowSmallestX = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY.y){
					yellowSmallestY = yellowBLOBList[i][j];
				}
			}
		}

		break;
	case 's':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueLargestX = Point(0, blueBLOBImg.rows / 2);
		blueSmallestY = Point(blueBLOBImg.cols / 2,blueBLOBImg.rows);
		blueLargestY = Point(blueBLOBImg.cols / 2, 0);
		yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
		yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x > blueLargestX.x){
					blueLargestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].y < blueSmallestY.y){
					blueSmallestY = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].y > blueLargestY.y){
					blueLargestY = blueBLOBList[i][j];
				}
			}
		}

		for (int i = 0; i < yellowBLOBList.size(); i++){
			for (int j = 1; j < yellowBLOBList[i].size(); j++){
				if (yellowBLOBList[i][j].x > yellowLargestX.x){
					yellowLargestX = yellowBLOBList[i][j];
				}
				if (yellowBLOBList[i][j].y < yellowSmallestY.y){
					yellowSmallestY = yellowBLOBList[i][j];
				}
			}
		}

		break;
	case 't':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');

		blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows / 2);
		blueLargestX = Point(0, blueBLOBImg.rows / 2);
		blueLargestY = Point(blueBLOBImg.cols / 2, 0);
		blueDistanceX = blueLargestX.x - blueSmallestX.x;
		yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
		yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
		yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);
		yellowLargestY = Point(yellowBLOBImg.cols / 2, 0);

		for (int i = 0; i < blueBLOBList.size(); i++){
			for (int j = 1; j < blueBLOBList[i].size(); j++){
				if (blueBLOBList[i][j].x < blueSmallestX.x){
					blueSmallestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].x > blueLargestX.x){
					blueLargestX = blueBLOBList[i][j];
				}
				if (blueBLOBList[i][j].y > blueLargestY.y){
					blueLargestY = blueBLOBList[i][j];
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

		yellowCenter = Point(yellowSmallestX.x + (yellowLargestX.x - yellowSmallestX.x) / 2, yellowSmallestY.y + (yellowLargestY.y - yellowSmallestY.y) / 2);

		break;
	}
}

void Recognizer::compareFeatures(char letter, bool leftHand){
	letterFound = false;
	hasBeenFound = Mat::zeros(50,50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			if (blueLargestX.x > yellowSmallestX.x)
				cout << "Your thumb has to be on the right side of your index finger" << endl;
			if ((yellowSmallestX.x - blueLargestX.x) > 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (blueLargestX.x <= yellowSmallestX.x && (yellowSmallestX.x - blueLargestX.x) <= 50)
				letterFound = true;
			break;
		case 'b':
			redDistanceX = redLargestX.x - redSmallestX.x;
			if (yellowCenter.x > redLargestX.x - redDistanceX / 4)
				cout << "move your thumb to the other side of the index finger" << endl;
			if (yellowCenter.x < redSmallestX.x + redDistanceX / 4)
				cout << "how did you do this? O.O" << endl;
			if (yellowCenter.x < redLargestX.x - redDistanceX / 4 && yellowCenter.x > redSmallestX.x + redDistanceX / 4)
				letterFound = true;
			break;
		case 'f':
			if (yellowSmallestY.y > blueLargestY.y)
				cout << "your thumb has to be below your index finger" << endl;
			if (yellowLargestX.x > blueLargestX.x + 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowLargestX.x < blueLargestX.x - 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowSmallestY.y < redLargestY.y)
				cout << "strecth out your middle, ring and little finger" << endl;
			if (redLargestX.x > blueLargestX.x)
				cout << "your index finger has to be below your little finger" << endl;
			if (redBLOBList.size() < 3)
				cout << "make sure all your fingers are visible in the image" << endl;
			if (yellowSmallestY.y > blueLargestY.y && (yellowLargestX.x < blueLargestX.x + 50 && yellowLargestX.x > blueLargestX.x - 50) && yellowSmallestY.y > redLargestY.y && redLargestX.x < blueLargestX.x && redBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 'l':
			if (blueLargestX.x > redLargestX.x)
				cout << "move your index finger more to your right" << endl;
			if (redLargestX.x > yellowSmallestX.x)
				cout << "strecth your thumb" << endl;
			if (yellowSmallestY.y < blueSmallestY.y)
				cout << "strecth your thumb" << endl;
			if (blueBLOBList.size() < 4)
				cout << "make sure all your finger are visible in the image" << endl;
			if (redBLOBList.size() < 2)
				cout << "make sure all your finger are visible in the image" << endl;
			if (blueLargestX.x < redLargestX.x && redLargestX.x < yellowSmallestX.x && yellowSmallestY.y > blueSmallestY.y && blueBLOBList.size() >= 4 && redBLOBList.size() >= 2)
				letterFound = true;
			break;
		case 's':
			if (yellowLargestX.x > blueLargestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (yellowSmallestY.y < blueSmallestY.y)
				cout << "move your thumb down" << endl;
			if (yellowSmallestY.y > blueLargestY.y)
				cout << "move your thumb up" << endl;
			if (blueBLOBList.size() < 3)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestX.x < blueLargestX.x && yellowSmallestY.y > blueSmallestY.y && yellowSmallestY.y < blueLargestY.y && blueBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 't':
			if (yellowLargestY.y > blueLargestY.y)
				cout << "move your thumb up a bit" << endl;
			if (yellowCenter.x < blueSmallestX.x + 3 * (blueDistanceX / 4) - 10)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (yellowCenter.x > blueLargestX.x)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (blueBLOBList.size() < 5)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestY.y < blueLargestY.y && yellowCenter.x > blueSmallestX.x + 3 * (blueDistanceX / 4) - 10 && yellowCenter.x < blueLargestX.x && blueBLOBList.size() >= 5)
				letterFound = true;
			break;
		default:
			cout << "compareFeatures has not been parsed a valid char." << endl;
		}
	}
	else{
		switch (letter){
		case 'a':
			if (blueLargestX.x < yellowSmallestX.x)
				cout << "Your thumb has to be on the left side of your index finger" << endl;
			if ((blueSmallestX.x - yellowLargestX.x) > 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (blueSmallestX.x >= yellowLargestX.x && (blueSmallestX.x - yellowLargestX.x) <= 50)
				letterFound = true;
			break;
		case 'b':
			redDistanceX = redLargestX.x - redSmallestX.x;
			if (yellowCenter.x > redLargestX.x - redDistanceX / 4)
				cout << "How did you do this? o.O" << endl;
			if (yellowCenter.x < redSmallestX.x + redDistanceX / 4)
				cout << "move your thumb to the other side of your index finger" << endl;
			if (yellowCenter.x < redLargestX.x - redDistanceX / 4 && yellowCenter.x > redSmallestX.x + redDistanceX / 4)
				letterFound = true;
			break;
		case 'f':
			if (yellowSmallestY.y > blueLargestY.y)
				cout << "your thumb has to be below your index finger" << endl;
			if (yellowLargestX.x > blueLargestX.x + 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowLargestX.x < blueLargestX.x - 50)
				cout << "move your thumb closer to your index finger" << endl;
			if (yellowSmallestY.y < redLargestY.y)
				cout << "strecth out your middle, ring and little finger" << endl;
			if (redSmallestX.x < blueLargestX.x)
				cout << "your index finger has to be left of your ring finger" << endl;
			if (redBLOBList.size() < 3)
				cout << "make sure all your fingers are visible in the image" << endl;
			if (yellowSmallestY.y > blueLargestY.y && (yellowLargestX.x < blueLargestX.x + 50 && yellowLargestX.x > blueLargestX.x - 50) && yellowSmallestY.y > redLargestY.y && redSmallestX.x > blueLargestX.x && redBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 'l':
			if (blueSmallestX.x < redSmallestX.x)
				cout << "move your index finger more to your left" << endl;
			if (redSmallestX.x < yellowLargestX.x)
				cout << "strecth your thumb" << endl;
			if (yellowSmallestY.y < blueSmallestY.y)
				cout << "strecth your thumb" << endl;
			if (blueBLOBList.size() < 4)
				cout << "make sure all your finger are visible in the image" << endl;
			if (redBLOBList.size() < 2)
				cout << "make sure all your finger are visible in the image" << endl;
			if (blueSmallestX.x > redSmallestX.x && redSmallestX.x > yellowLargestX.x && yellowSmallestY.y > blueSmallestY.y && blueBLOBList.size() >= 4 && redBLOBList.size() >= 2)
				letterFound = true;
			break;
		case 's':
			if (yellowLargestX.x > blueLargestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (yellowSmallestY.y < blueSmallestY.y)
				cout << "move your thumb down" << endl;
			if (yellowSmallestY.y > blueLargestY.y)
				cout << "move your thumb up" << endl;
			if (blueBLOBList.size() < 3)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestX.x < blueLargestX.x && yellowSmallestY.y > blueSmallestY.y && yellowSmallestY.y < blueLargestY.y && blueBLOBList.size() >= 3)
				letterFound = true;
			break;
		case 't':
			if (yellowLargestY.y > blueLargestY.y)
				cout << "move your thumb up a bit" << endl;
			if (yellowCenter.x > blueLargestX.x - 2 * (blueDistanceX / 4) + 10)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (yellowCenter.x < blueSmallestX.x)
				cout << "move your thumb in between your index and middle finger" << endl;
			if (blueBLOBList.size() < 5)
				cout << "make sure all your finger are visible in the image" << endl;
			if (yellowLargestY.y < blueLargestY.y && yellowCenter.x < blueLargestX.x - 2 * (blueDistanceX / 4) + 10 && yellowCenter.x > blueSmallestX.x && blueBLOBList.size() >= 5)
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

	blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows / 2);
	blueSmallestY = Point(blueBLOBImg.cols / 2, blueBLOBImg.rows);
	greenSmallestX = Point(greenBLOBImg.cols, greenBLOBImg.rows / 2);
	greenSmallestY = Point(greenBLOBImg.cols / 2, greenBLOBImg.rows);
	pinkSmallestX = Point(pinkBLOBImg.cols, pinkBLOBImg.rows / 2);
	pinkSmallestY = Point(pinkBLOBImg.cols / 2, pinkBLOBImg.rows);
	redSmallestX = Point(redBLOBImg.cols, redBLOBImg.rows / 2);
	redSmallestY = Point(redBLOBImg.cols / 2, redBLOBImg.rows);
	yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
	yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);

	blueLargestX = Point(0, blueBLOBImg.rows / 2);
	blueLargestY = Point(blueBLOBImg.cols / 2, 0);
	greenLargestX = Point(0, greenBLOBImg.rows / 2);
	greenLargestY = Point(greenBLOBImg.cols / 2, 0);
	pinkLargestX = Point(0, greenBLOBImg.rows / 2);
	pinkLargestY = Point(greenBLOBImg.cols / 2, 0);
	redLargestX = Point(0, redBLOBImg.rows / 2);
	redLargestY = Point(redBLOBImg.cols / 2, 0);
	yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
	yellowLargestY = Point(yellowBLOBImg.cols / 2, 0);

	for (int i = 0; i < blueBLOBList.size(); i++){
		for (int j = 1; j < blueBLOBList[i].size(); j++){
			if (blueBLOBList[i][j].x < blueSmallestX.x){
				blueSmallestX = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].x > blueLargestX.x){
				blueLargestX = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].y < blueSmallestY.y){
				blueSmallestY = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].y > blueLargestY.y){
				blueLargestY = blueBLOBList[i][j];
			}
		}
	}

	blueCenter = Point(blueSmallestX.x + (blueLargestX.x - blueSmallestX.x) / 2, blueSmallestY.y + (blueLargestY.y - blueSmallestY.y) / 2);

	for (int i = 0; i < greenBLOBList.size(); i++){
		for (int j = 1; j < greenBLOBList[i].size(); j++){
			if (greenBLOBList[i][j].x < greenSmallestX.x){
				greenSmallestX = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].x > greenLargestX.x){
				greenLargestX = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].y < greenSmallestY.y){
				greenSmallestY = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].y > greenLargestY.y){
				greenLargestY = greenBLOBList[i][j];
			}
		}
	}

	greenCenter = Point(greenSmallestX.x + (greenLargestX.x - greenSmallestX.x) / 2, greenSmallestY.y + (greenLargestY.y - greenSmallestY.y) / 2);

	for (int i = 0; i < pinkBLOBList.size(); i++){
		for (int j = 1; j < pinkBLOBList[i].size(); j++){
			if (pinkBLOBList[i][j].x < pinkSmallestX.x){
				pinkSmallestX = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].x > pinkLargestX.x){
				pinkLargestX = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].y < pinkSmallestY.y){
				pinkSmallestY = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].y > pinkLargestY.y){
				pinkLargestY = pinkBLOBList[i][j];
			}
		}
	}

	pinkCenter = Point(pinkSmallestX.x + (pinkLargestX.x - pinkSmallestX.x) / 2, pinkSmallestY.y + (pinkLargestY.y - pinkSmallestY.y) / 2);

	for (int i = 0; i < redBLOBList.size(); i++){
		for (int j = 1; j < redBLOBList[i].size(); j++){
			if (redBLOBList[i][j].x < redSmallestX.x){
				redSmallestX = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].x > redLargestX.x){
				redLargestX = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].y < redSmallestY.y){
				redSmallestY = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].y > redLargestY.y){
				redLargestY = redBLOBList[i][j];
			}
		}
	}

	redCenter = Point(redSmallestX.x + (redLargestX.x - redSmallestX.x) / 2, redSmallestY.y + (redLargestY.y - redSmallestY.y) / 2);

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

	yellowCenter = Point(yellowSmallestX.x + (yellowLargestX.x - yellowSmallestX.x) / 2, yellowSmallestY.y + (yellowLargestY.y - yellowSmallestY.y) / 2);
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
			if (greenLargestY.y < redSmallestY.y - errorAllowance)
				cout << "make sure your tumb is below your index finger" << endl;
			if (greenLargestY.y > redSmallestY.y + errorAllowance)
				cout << "move your thumb closer to your index finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& greenLargestY.y > redSmallestY.y - errorAllowance && greenLargestY.y < redSmallestY.y + errorAllowance)
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
			if (yellowSmallestY.y < blueSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY.y > blueSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y < pinkSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y > pinkSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y < greenSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y > greenSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x > greenLargestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (redCenter.x < pinkSmallestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (greenCenter.y > yellowCenter.y)
				cout << "move your thumb in front of your index finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY.y > blueSmallestY.y - errorAllowance*multiplier && yellowSmallestY.y < blueSmallestY.y + errorAllowance*multiplier
				&& blueSmallestY.y > pinkSmallestY.y - errorAllowance*multiplier && blueSmallestY.y < pinkSmallestY.y + errorAllowance*multiplier
				&& pinkSmallestY.y > greenSmallestY.y - errorAllowance*multiplier && pinkSmallestY.y < greenSmallestY.y + errorAllowance*multiplier
				&& redCenter.x < greenLargestX.x && redCenter.x > pinkSmallestX.x
				&& greenCenter.y < yellowCenter.y)
				letterFound = true;
			break;
		case 't':
			if (yellowCenter.x > blueCenter.x || blueCenter.x > pinkCenter.x || pinkCenter.x > greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY.y < blueSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY.y > blueSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y < pinkSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y > pinkSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y < greenSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y > greenSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x > greenLargestX.x || redCenter.x < pinkSmallestX.x)
				cout << "move your thumb between your index and middle finger" << endl;

			if (yellowCenter.x < blueCenter.x && blueCenter.x < pinkCenter.x && pinkCenter.x < greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY.y > blueSmallestY.y - errorAllowance*multiplier && yellowSmallestY.y < blueSmallestY.y + errorAllowance*multiplier
				&& blueSmallestY.y > pinkSmallestY.y - errorAllowance*multiplier && blueSmallestY.y < pinkSmallestY.y + errorAllowance*multiplier
				&& pinkSmallestY.y > greenSmallestY.y - errorAllowance*multiplier && pinkSmallestY.y < greenSmallestY.y + errorAllowance*multiplier
				&& redCenter.x < greenLargestX.x && redCenter.x > pinkSmallestX.x)
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
			if (greenLargestY.y < redSmallestY.y - errorAllowance)
				cout << "make sure your tumb is below your index finger" << endl;
			if (greenLargestY.y > redSmallestY.y + errorAllowance)
				cout << "move your thumb closer to your index finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& greenLargestY.y > redSmallestY.y - errorAllowance && greenLargestY.y < redSmallestY.y + errorAllowance)
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
			if (yellowSmallestY.y < blueSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY.y > blueSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y < pinkSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y > pinkSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y < greenSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y > greenSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x < greenSmallestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (redCenter.x > pinkLargestX.x)
				cout << "move your thumb in front of your index finger" << endl;
			if (greenCenter.y > yellowCenter.y)
				cout << "move your thumb in front of your index finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY.y > blueSmallestY.y - errorAllowance*multiplier && yellowSmallestY.y < blueSmallestY.y + errorAllowance*multiplier
				&& blueSmallestY.y > pinkSmallestY.y - errorAllowance*multiplier && blueSmallestY.y < pinkSmallestY.y + errorAllowance*multiplier
				&& pinkSmallestY.y > greenSmallestY.y - errorAllowance*multiplier && pinkSmallestY.y < greenSmallestY.y + errorAllowance*multiplier
				&& redCenter.x > greenSmallestX.x && redCenter.x < pinkLargestX.x
				&& greenCenter.y < yellowCenter.y)
				letterFound = true;
			break;
		case 't':
			if (yellowCenter.x < blueCenter.x || blueCenter.x < pinkCenter.x || pinkCenter.x < greenCenter.x)
				cout << "please make sure your fingers are in the right succession" << endl;
			if (yellowSmallestY.y < blueSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (yellowSmallestY.y > blueSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y < pinkSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (blueSmallestY.y > pinkSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y < greenSmallestY.y - errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (pinkSmallestY.y > greenSmallestY.y + errorAllowance*multiplier)
				cout << "make sure your fingers are alligned" << endl;
			if (redCenter.x < greenSmallestX.x || redCenter.x > pinkLargestX.x)
				cout << "move your thumb between your index and middle finger" << endl;

			if (yellowCenter.x > blueCenter.x && blueCenter.x > pinkCenter.x && pinkCenter.x > greenCenter.x /*if the fingers are in the right succession*/
				&& yellowSmallestY.y > blueSmallestY.y - errorAllowance*multiplier && yellowSmallestY.y < blueSmallestY.y + errorAllowance*multiplier
				&& blueSmallestY.y > pinkSmallestY.y - errorAllowance*multiplier && blueSmallestY.y < pinkSmallestY.y + errorAllowance*multiplier
				&& pinkSmallestY.y > greenSmallestY.y - errorAllowance*multiplier && pinkSmallestY.y < greenSmallestY.y + errorAllowance*multiplier
				&& redCenter.x > greenSmallestX.x && redCenter.x < pinkLargestX.x)
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

	blueSmallestX = Point(blueBLOBImg.cols, blueBLOBImg.rows / 2);
	blueSmallestY = Point(blueBLOBImg.cols / 2, blueBLOBImg.rows);
	greenSmallestX = Point(greenBLOBImg.cols, greenBLOBImg.rows / 2);
	greenSmallestY = Point(greenBLOBImg.cols / 2, greenBLOBImg.rows);
	pinkSmallestX = Point(pinkBLOBImg.cols, pinkBLOBImg.rows / 2);
	pinkSmallestY = Point(pinkBLOBImg.cols / 2, pinkBLOBImg.rows);
	redSmallestX = Point(redBLOBImg.cols, redBLOBImg.rows / 2);
	redSmallestY = Point(redBLOBImg.cols / 2, redBLOBImg.rows);
	yellowSmallestX = Point(yellowBLOBImg.cols, yellowBLOBImg.rows / 2);
	yellowSmallestY = Point(yellowBLOBImg.cols / 2, yellowBLOBImg.rows);

	blueLargestX = Point(0, blueBLOBImg.rows / 2);
	blueLargestY = Point(blueBLOBImg.cols / 2, 0);
	greenLargestX = Point(0, greenBLOBImg.rows / 2);
	greenLargestY = Point(greenBLOBImg.cols / 2, 0);
	pinkLargestX = Point(0, pinkBLOBImg.rows / 2);
	pinkLargestY = Point(pinkBLOBImg.cols / 2, 0);
	redLargestX = Point(0, redBLOBImg.rows / 2);
	redLargestY = Point(redBLOBImg.cols / 2, 0);
	yellowLargestX = Point(0, yellowBLOBImg.rows / 2);
	yellowLargestY = Point(yellowBLOBImg.cols / 2, 0);

	lengthYelBlue = 0;

	for (int i = 0; i < blueBLOBList.size(); i++){
		for (int j = 1; j < blueBLOBList[i].size(); j++){
			if (blueBLOBList[i][j].x < blueSmallestX.x){
				blueSmallestX = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].x > blueLargestX.x){
				blueLargestX = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].y < blueSmallestY.y){
				blueSmallestY = blueBLOBList[i][j];
			}
			if (blueBLOBList[i][j].y > blueLargestY.y){
				blueLargestY = blueBLOBList[i][j];
			}
		}
	}

	blueCenter = Point(blueSmallestX.x + (blueLargestX.x - blueSmallestX.x) / 2, blueSmallestY.y + (blueLargestY.y - blueSmallestY.y) / 2);

	for (int i = 0; i < greenBLOBList.size(); i++){
		for (int j = 1; j < greenBLOBList[i].size(); j++){
			if (greenBLOBList[i][j].x < greenSmallestX.x){
				greenSmallestX = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].x > greenLargestX.x){
				greenLargestX = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].y < greenSmallestY.x){
				greenSmallestY = greenBLOBList[i][j];
			}
			if (greenBLOBList[i][j].y > greenLargestY.y){
				greenLargestY = greenBLOBList[i][j];
			}
		}
	}

	greenCenter = Point(greenSmallestX.x + (greenLargestX.x - greenSmallestX.x) / 2, greenSmallestY.y + (greenLargestY.y - greenSmallestY.y) / 2);

	for (int i = 0; i < pinkBLOBList.size(); i++){
		for (int j = 1; j < pinkBLOBList[i].size(); j++){
			if (pinkBLOBList[i][j].x < pinkSmallestX.x){
				pinkSmallestX = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].x > pinkLargestX.x){
				pinkLargestX = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].y < pinkSmallestY.y){
				pinkSmallestY = pinkBLOBList[i][j];
			}
			if (pinkBLOBList[i][j].y > pinkLargestY.y){
				pinkLargestY = pinkBLOBList[i][j];
			}
		}
	}

	pinkCenter = Point(pinkSmallestX.x + (pinkLargestX.x - pinkSmallestX.x) / 2, pinkSmallestY.y + (pinkLargestY.y - pinkSmallestY.y) / 2);

	for (int i = 0; i < redBLOBList.size(); i++){
		for (int j = 1; j < redBLOBList[i].size(); j++){
			if (redBLOBList[i][j].x < redSmallestX.x){
				redSmallestX = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].x > redLargestX.x){
				redLargestX = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].y < redSmallestY.y){
				redSmallestY = redBLOBList[i][j];
			}
			if (redBLOBList[i][j].y > redLargestY.y){
				redLargestY = redBLOBList[i][j];
			}
		}
	}

	redCenter = Point(redSmallestX.x + (redLargestX.x - redSmallestX.x) / 2, redSmallestY.y + (redLargestY.y - redSmallestY.y) / 2);

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

	yellowCenter = Point(yellowSmallestX.x + (yellowLargestX.x - yellowSmallestX.x) / 2, yellowSmallestY.y + (yellowLargestY.y - yellowSmallestY.y) / 2);
}

void Recognizer::vectorRecognizer(char letter, bool leftHand){
	BLOBAnalyze(letter);
	extractFeaturesVector();

	letterFound = false;
	hasBeenFound = Mat::zeros(50, 50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			lengthYelBlue = sqrt(pow(blueSmallestX.x - yellowCenter.x, 2.0f) + pow(blueSmallestX.y - yellowCenter.y, 2.0f));
			lengthBlueYel = sqrt(pow(blueCenter.x - yellowCenter.x, 2.0f) + pow(blueCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthYelBlue / lengthBlueYel;

			currentSign.push_back(ratio);
			
			idealSign.push_back (1.0f);
			
			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f) + pow(idealSign[1] - currentSign[1], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;
			
			if (euclideanDistance < 1.0f)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'b':
			lengthYelRed = sqrt(pow(redSmallestX.x - yellowCenter.x, 2.0f) + pow(redSmallestX.y - yellowCenter.y, 2.0f));
			lengthRedYel = sqrt(pow(redLargestX.x - yellowCenter.x, 2.0f) + pow(redLargestX.y - yellowCenter.y, 2.0f));

			ratio = lengthYelRed / lengthRedYel;

			currentSign.push_back(ratio);

			idealSign.push_back(1.0f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			if (euclideanDistance < 1.0f)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);
				
			break;
		case 'f':
			lengthYelBlue = sqrt(pow(blueLargestY.x - yellowCenter.x, 2.0f) + pow(blueLargestY.y - yellowCenter.y, 2.0f));
			lengthYelRed = sqrt(pow(redLargestY.x - yellowCenter.x, 2.0f) + pow(redLargestY.y - yellowCenter.y, 2.0f));

			ratio = (float)lengthYelBlue / (float)lengthYelRed;

			currentSign.push_back(ratio);
			idealSign.push_back(0.3f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			if (euclideanDistance < 0.09f)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'l':
			lengthYelRed = sqrt(pow(redCenter.x - yellowCenter.x, 2.0f) + pow(redCenter.y - yellowCenter.y, 2.0f));
			lengthBlueRed = sqrt(pow(redCenter.x - blueSmallestX.x, 2.0f) + pow(redCenter.y - blueSmallestX.y, 2.0f));

			ratio = lengthYelRed / lengthBlueRed;

			currentSign.push_back(ratio);
			idealSign.push_back(1.0f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.5f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;
			
			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 's':
			lengthYelBlue = sqrt(pow(yellowCenter.x - blueSmallestX.x, 2.0f) + pow(yellowCenter.y - blueSmallestX.y, 2.0f));

			blueSmallestY.x = yellowCenter.x;
			blueLargestY.x = yellowCenter.x;

			lengthBlue = sqrt(pow(blueLargestY.x - blueSmallestY.x, 2.0f) + pow(blueLargestY.y - blueSmallestY.y, 2.0f));

			ratio = lengthYelBlue / lengthBlue;

			currentSign.push_back(ratio);
			idealSign.push_back(1.6f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 't':
			yellowCenter.y = blueSmallestX.y;
			blueLargestX.y = blueSmallestX.y;

			lengthYelBlue = sqrt(pow(yellowCenter.x - blueSmallestX.x, 2.0f) + pow(yellowCenter.y - blueSmallestX.y, 2.0f));
			lengthBlueYel = sqrt(pow(yellowCenter.x - blueLargestX.x, 2.0f) + pow(yellowCenter.y - blueLargestX.y, 2.0f));

			ratio = lengthYelBlue / lengthBlueYel;

			currentSign.push_back(ratio);
			idealSign.push_back(3.7f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		default:
			cout << "vectorRecognizer was not passed a valid letter" << endl;
		}
	}
	else{
		switch (letter){
		case 'a':
			lengthYelBlue = sqrt(pow(blueLargestX.x - yellowCenter.x, 2.0f) + pow(blueLargestX.y - yellowCenter.y, 2.0f));
			lengthBlueYel = sqrt(pow(blueCenter.x - yellowCenter.x, 2.0f) + pow(blueCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthYelBlue / lengthBlueYel;

			currentSign.push_back(ratio);

			idealSign.push_back (1.0f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f) + pow(idealSign[1] - currentSign[1], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			if (euclideanDistance < 1.0f)
			letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'b':
			lengthYelRed = sqrt(pow(redLargestX.x - yellowCenter.x, 2.0f) + pow(redLargestX.y - yellowCenter.y, 2.0f));
			lengthRedYel = sqrt(pow(redSmallestX.x - yellowCenter.x, 2.0f) + pow(redSmallestX.y - yellowCenter.y, 2.0f));

			ratio = lengthYelRed / lengthRedYel;

			currentSign.push_back(ratio);

			idealSign.push_back(1.0f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			if (euclideanDistance < 1.0f)
			letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'f':
			lengthYelBlue = sqrt(pow(blueLargestY.x - yellowCenter.x, 2.0f) + pow(blueLargestY.y - yellowCenter.y, 2.0f));
			lengthYelRed = sqrt(pow(redLargestY.x - yellowCenter.x, 2.0f) + pow(redLargestY.y - yellowCenter.y, 2.0f));

			ratio = (float)lengthYelBlue / (float)lengthYelRed;

			currentSign.push_back(ratio);
			idealSign.push_back(0.3f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			if (euclideanDistance < 0.09f)
				letterFound = true;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'l':
			lengthYelRed = sqrt(pow(redCenter.x - yellowCenter.x, 2.0f) + pow(redCenter.y - yellowCenter.y, 2.0f));
			lengthBlueRed = sqrt(pow(redCenter.x - blueLargestX.x, 2.0f) + pow(redCenter.y - blueLargestX.y, 2.0f));

			ratio = lengthYelRed / lengthBlueRed;

			currentSign.push_back(ratio);
			idealSign.push_back(1.0f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.5f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 's':
			lengthYelBlue = sqrt(pow(yellowCenter.x - blueLargestX.x, 2.0f) + pow(yellowCenter.y - blueLargestX.y, 2.0f));

			blueSmallestY.x = yellowCenter.x;
			blueLargestY.x = yellowCenter.x;

			lengthBlue = sqrt(pow(blueLargestY.x - blueSmallestY.x, 2.0f) + pow(blueSmallestY.y - blueLargestY.y, 2.0f));

			ratio = lengthYelBlue / lengthBlue;

			currentSign.push_back(ratio);
			idealSign.push_back(1.6f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 't':
			yellowCenter.y = blueSmallestX.y;
			blueLargestX.y = blueSmallestX.y;

			lengthYelBlue = sqrt(pow(yellowCenter.x - blueSmallestX.x, 2.0f) + pow(yellowCenter.y - blueSmallestX.y, 2.0f));
			lengthBlueYel = sqrt(pow(yellowCenter.x - blueLargestX.x, 2.0f) + pow(yellowCenter.y - blueLargestX.y, 2.0f));

			ratio = lengthYelBlue / lengthBlueYel;

			currentSign.push_back(ratio);
			idealSign.push_back(3.7f);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			if (euclideanDistance < 0.03f)
				letterFound = true;

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

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

void Recognizer::vectorRecognizerGlove2(char letter, bool leftHand){
	BLOBAnalyze(letter);
	extractFeaturesVector();

	letterFound = false;
	hasBeenFound = Mat::zeros(50, 50, CV_8UC3);

	if (leftHand){
		switch (letter){
		case 'a':
			lengthRedGreen = sqrt(pow(redCenter.x - greenCenter.x, 2.0f) + pow(redCenter.y - greenCenter.y, 2.0f));
			lengthPinkYel = sqrt(pow(pinkCenter.x - yellowCenter.x, 2.0f) + pow(pinkCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthRedGreen / lengthPinkYel;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);
			

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			/*if (euclideanDistance < x)
				letterFound = true;*/

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'b':
			lengthRedGreen = sqrt(pow(redCenter.x - greenCenter.x, 2.0f) + pow(redCenter.y - greenCenter.y, 2.0f));
			lengthGreenYel = sqrt(pow(greenCenter.x - yellowCenter.x, 2.0f) + pow(greenCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthGreenYel / lengthRedGreen;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			/*if (euclideanDistance < x)
				letterFound = true;*/

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'f':
			lengthRedGreen = sqrt(pow(redCenter.x - greenCenter.x, 2.0f) + pow(redCenter.y - greenCenter.y, 2.0f));
			lengthRedPink = sqrt(pow(redLargestY.x - pinkCenter.x, 2.0f) + pow(redLargestY.y - pinkCenter.y, 2.0f));

			ratio = lengthRedGreen / lengthRedPink;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			/*if (euclideanDistance < x)
				letterFound = true;*/

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 'l':
			lengthRedGreen = sqrt(pow(redCenter.x - greenCenter.x, 2.0f) + pow(redCenter.y - greenCenter.y, 2.0f));
			lengthGreenYel = sqrt(pow(greenCenter.x - yellowCenter.x, 2.0f) + pow(greenCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthRedGreen / lengthGreenYel;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			/*if (euclideanDistance < x)
				letterFound = true;*/

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 's':
			lengthRedBlue = sqrt(pow(redCenter.x - blueCenter.x, 2.0f) + pow(redCenter.y - blueCenter.y, 2.0f));
			lengthRedYel = sqrt(pow(redCenter.x - yellowCenter.x, 2.0f) + pow(redCenter.y - yellowCenter.y, 2.0f));

			ratio = lengthRedBlue / lengthRedYel;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			/*if (euclideanDistance < x)
				letterFound = true;*/

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

			break;
		case 't':
			lengthRedGreen = sqrt(pow(redSmallestY.x - greenCenter.x, 2.0f) + pow(redSmallestY.y - greenCenter.y, 2.0f));
			lengthRedYel = sqrt(pow(redSmallestY.x - yellowCenter.x, 2.0f) + pow(redSmallestY.y - yellowCenter.y, 2.0f));

			ratio = lengthRedGreen / lengthRedYel;

			currentSign.push_back(ratio);

			//idealSign.push_back(x);

			euclideanDistance = sqrt(pow(idealSign[0] - currentSign[0], 2.0f));

			/*if (euclideanDistance < x)
				letterFound = true;*/

			cout << "ratio: " << ratio << " | euc: " << euclideanDistance << endl;

			currentSign.empty();
			currentSign.resize(0);

			idealSign.empty();
			idealSign.resize(0);

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
	return euclideanDistance;
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