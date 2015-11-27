#include "Evaluator.h"

Evaluator::Evaluator(){
}

//start the timer for the parsed char
void Evaluator::startTimer(char letter, Mat img, int gloveNumber){
	currentLetter = letter;											//saving parsed char
	timerHasStarted = true;											//"starting" timer
	startTime = clock();											//check the current clock_tic and set startTime as this
	NormalVid.open("C:/Users/Patrick/Desktop/Vids/NormalVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), true); //the videoWriter opens the specified file, descripes the type each frame is, decides the frame reate, declares the size of the video, and wether or not it's a colour picture
	if (gloveNumber == 1){
		switch (letter){
		case 'a':
			blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		case 'b':
			redBLOBVid.open("C:/Users/Patrick/Desktop/Vids/RedBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			redTreshVid.open("C:/Users/Patrick/Desktop/Vids/RedThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		case 'f':
			blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			redBLOBVid.open("C:/Users/Patrick/Desktop/Vids/RedBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			redTreshVid.open("C:/Users/Patrick/Desktop/Vids/RedThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		case 'l':
			blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			redBLOBVid.open("C:/Users/Patrick/Desktop/Vids/RedBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			redTreshVid.open("C:/Users/Patrick/Desktop/Vids/RedThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		case 's':
			blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		case 't':
			blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
			break;
		default:
			cout << "Evaluator was not given a proper letter" << endl;
		}
	}
	else if (gloveNumber == 2){
		blueBLOBVid.open("C:/Users/Patrick/Desktop/Vids/BlueBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		blueTreshVid.open("C:/Users/Patrick/Desktop/Vids/BlueThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		greenBLOBVid.open("C:/Users/Patrick/Desktop/Vids/GreenBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		greenTreshVid.open("C:/Users/Patrick/Desktop/Vids/GreenThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		pinkBLOBVid.open("C:/Users/Patrick/Desktop/Vids/PinkBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		pinkTreshVid.open("C:/Users/Patrick/Desktop/Vids/PinkThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		redBLOBVid.open("C:/Users/Patrick/Desktop/Vids/RedBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		redTreshVid.open("C:/Users/Patrick/Desktop/Vids/RedThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		yellowBLOBVid.open("C:/Users/Patrick/Desktop/Vids/YellowBLOBVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
		yellowTreshVid.open("C:/Users/Patrick/Desktop/Vids/YellowThreshVid.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), false);
	}
	else
		cout << "guess we're setting thresholds" << endl;
}

//stop the timer and write to the file with the parsed name
void Evaluator::stopTimer(){										//saving the parsed string
	endTime = clock();												//check the current clock_tic and set stopTime as this

	clockTicsTaken = endTime - startTime;							//calculating clockTicsTaken
	timeInSeconds = clockTicsTaken / (double)CLOCKS_PER_SEC;		//calculating time taken in seconds

	writeToFile();			//writing to the specified text file

	timerHasStarted = false;										//"stopping" the timer

	NormalVid.release();											//stops the video streams
	blueBLOBVid.release();
	blueTreshVid.release();
	greenBLOBVid.release();
	greenTreshVid.release();
	pinkBLOBVid.release();
	pinkTreshVid.release();
	redBLOBVid.release();
	redTreshVid.release();
	yellowBLOBVid.release();
	yellowTreshVid.release();
}

//writing to the specified file
void Evaluator::writeToFile(){
	outputFile.open("C:/Users/Patrick/Desktop/Vids/Data.txt");										//"opening" the text file
	dataToSend << "\nSign '" << currentLetter << "': clockTicsTaken = " << clockTicsTaken << ". timeInSeconds = " << timeInSeconds << ". euclideanDistance = " << euclideanDistance << ".";	//creating a string to send to the file
	outputFile << dataToSend.str();									//sending the created string to the file
	outputFile.close();												//"closing" the text file
}

//save videoStream to file
void Evaluator::saveThreshVid(Mat img, Mat blueThreshImg, Mat greenThreshImg, Mat pinkThreshImg, Mat redThreshImg, Mat yellowThreshImg, char letter, int gloveNumber){
		NormalVid.write(img);										//save the frame to the videoWriter
		if (gloveNumber == 1){
			switch (letter){
			case 'a':
				blueTreshVid.write(blueThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			case 'b':
				redTreshVid.write(redThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			case 'f':
				blueTreshVid.write(blueThreshImg);
				redTreshVid.write(redThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			case 'l':
				blueTreshVid.write(blueThreshImg);
				redTreshVid.write(redThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			case 's':
				blueTreshVid.write(blueThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			case 't':
				blueTreshVid.write(blueThreshImg);
				yellowTreshVid.write(yellowThreshImg);
				break;
			default:
				cout << "Evaluator was not given a proper letter" << endl;
			}
		}
		else{
			blueTreshVid.write(blueThreshImg);
			greenTreshVid.write(greenThreshImg);
			pinkTreshVid.write(pinkThreshImg);
			redTreshVid.write(redThreshImg);
			yellowTreshVid.write(yellowThreshImg);
		}
}

//save videoStream to file
void Evaluator::saveBLOBVid(Mat blueBLOBImg, Mat greenBLOBImg, Mat pinkBLOBImg, Mat redBLOBImg, Mat yellowBLOBImg, char letter, int gloveNumber){
	if (gloveNumber == 1){
		switch (letter){
		case 'a':
			blueBLOBVid.write(blueBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		case 'b':
			redBLOBVid.write(redBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		case 'f':
			blueBLOBVid.write(blueBLOBImg);
			redBLOBVid.write(redBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		case 'l':
			blueBLOBVid.write(blueBLOBImg);
			redBLOBVid.write(redBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		case 's':
			blueBLOBVid.write(blueBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		case 't':
			blueBLOBVid.write(blueBLOBImg);
			yellowBLOBVid.write(yellowBLOBImg);
			break;
		default:
			cout << "Evaluator was not given a proper letter" << endl;
		}
	}
	else{
		blueBLOBVid.write(blueBLOBImg);
		greenBLOBVid.write(greenBLOBImg);
		pinkBLOBVid.write(pinkBLOBImg);
		redBLOBVid.write(redBLOBImg);
		yellowBLOBVid.write(yellowBLOBImg);
	}
}

//set euclidean distance 
void Evaluator::setEuclideanDistance(float eud){
	euclideanDistance = eud;
}

//get the bool timerHasStarted
bool Evaluator::getTimerHasStarted(){
	return timerHasStarted;
}