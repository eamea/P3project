#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "BLOBDetector.h"
#include "Recognizer.h"
#include "Evaluator.h"

using namespace std;
using namespace cv;


char letters[] {'a', 'b', 'f', 'l', 's', 't'};							//an array containing chars for the letters we are going to learn

int main()
{
	Detector detector(5);												//instantiating a detector with kernel size 5
	Recognizer recognizer(detector);									//instantiating a recognizer
	Evaluator evaluator;												//instantiating an evaluator

	VideoCapture stream(1);												//capturing a stream from webcam (x)

	Mat capturedFrame;													//for holding the current frame
	bool leftHand = true;												//true if the user chose left hand, false if they chose right hand
	char letter = 'a';													//the letter to sign

	stream.read(capturedFrame);											//loads the first image so we can get the width and height of the video
	evaluator.openFiles(capturedFrame);									//opens all files so we can save the evaluation data

	/*
	 * FOR SETTING THRESHOLDS ONLY!
	 */
	Mat output;																//holds the processed frame
	detector.createTrackbars();											//creates a window with trackbars

	int gloveNumber = 3;													//CHANGE BASED ON WHAT GLOVE YOU'RE TESTING!
																			//1 = fingertip-glove, 2 = wholefinger-glove, 3 = set thresholds
	while (true){
		stream.read(capturedFrame);											//reading a frame from the stream

		if (gloveNumber == 1){

			detector.thresholdImageFor(capturedFrame, letter);				//thresholding for the chosen letter

			//imshow("blue thresh", detector.getBlueThreshImg());			//showing thresholded images
			//imshow("green thresh", detector.getGreenThreshImg());
			//imshow("red thresh", detector.getRedThreshImg());
			//imshow("yellow thresh", detector.getYellowThreshImg());

			recognizer.setDetector(detector);								//setting the detector for the recognizer

			if (evaluator.getTimerHasStarted() == false)					//if timer isn't currently going
				evaluator.startTimer(letter, capturedFrame, gloveNumber);	//start timer
			else															//saves the thresholded videos to a file
				evaluator.saveThreshVid(capturedFrame, detector.getBlueThreshImg(), detector.getGreenThreshImg(), detector.getPinkThreshImg(), detector.getRedThreshImg(), detector.getYellowThreshImg(), letter, gloveNumber);	//ensures every frame is saved to the video file

			//recognizer.recognize(letter, leftHand);						//recognizing for the chosen letter.
			recognizer.vectorRecognizer(letter, leftHand);
			//saves the BLOB videos to files
			evaluator.saveBLOBVid(recognizer.getBlueBLOBImg(), recognizer.getGreenBLOBImg(), recognizer.getPinkBLOBImg(), recognizer.getRedBLOBImg(), recognizer.getYellowBLOBImg(), letter, gloveNumber);

			if (recognizer.getLetterFound() == true){				//if recognizer found the sign we looked for
				evaluator.setEuclideanDistance(recognizer.getEuclideanDistance());	//set euclidean distance
				evaluator.stopTimer();						//stop timer and write to file
			}

			if (!recognizer.getBlueBLOBImg().empty())
				imshow("blue blob", recognizer.getBlueBLOBImg());			//Showing BLOB-analyzed images
			if (!recognizer.getGreenBLOBImg().empty())
				imshow("green blob", recognizer.getGreenBLOBImg());
			if (!recognizer.getRedBLOBImg().empty())
				imshow("red blob", recognizer.getRedBLOBImg());
			if (!recognizer.getYellowBLOBImg().empty())
				imshow("yellow blob", recognizer.getYellowBLOBImg());
		}
		else if (gloveNumber == 2){
			detector.thresholdForGlove2(capturedFrame);					//thresholding

			
			imshow("blue thresh", detector.getBlueThreshImg());		//showing thresholded images
			imshow("green thresh", detector.getGreenThreshImg());
			imshow("pink thresh", detector.getPinkThreshImg());
			imshow("red thresh", detector.getRedThreshImg());
			imshow("yellow thresh", detector.getYellowThreshImg());

			recognizer.setDetector(detector);								//setting the detector for the recognizer

			if (evaluator.getTimerHasStarted() == false)					//if timer isn't currently going
				evaluator.startTimer(letter, capturedFrame, gloveNumber);	//start timer
			else															//saves the thresholded videos to files
				evaluator.saveThreshVid(capturedFrame, detector.getBlueThreshImg(), detector.getGreenThreshImg(), detector.getPinkThreshImg(), detector.getRedThreshImg(), detector.getYellowThreshImg(), letter, gloveNumber);	//ensures every frame is saved to the video file

			//recognizer.recognizeGlove2(letter, leftHand);					//recognizing for the chosen letter
			recognizer.vectorRecognizer(letter, leftHand);
			//saves the BLOB videos to files
			evaluator.saveBLOBVid(recognizer.getBlueBLOBImg(), recognizer.getGreenBLOBImg(), recognizer.getPinkBLOBImg(), recognizer.getRedBLOBImg(), recognizer.getYellowBLOBImg(), letter, gloveNumber);

			if (recognizer.getLetterFound() == true){				//if recognizer found the sign we looked for
				evaluator.setEuclideanDistance(recognizer.getEuclideanDistance());	//set euclidean distance
				evaluator.stopTimer();						//stop timer and write to file
			}

			//imshow("blue blob", recognizer.getBlueBLOBImg());			//showing BLOB-analyzed images
			//imshow("green blob", recognizer.getGreenBLOBImg());
			//imshow("pink blob", recognizer.getPinkBLOBImg());
			//imshow("red blob", recognizer.getRedBLOBImg());
			//imshow("yellow blob", recognizer.getYellowBLOBImg());
		}
		else{
			output = detector.segmentFrame(capturedFrame);				//segmenting current frame
			imshow("Thresholded", output);								//showing output
		}

		imshow("Original", capturedFrame);								//showing the original image
		
		if (waitKey(30) == 27)	{										//(check every 30 ms) if 'esc'-key has been pressed by user
			evaluator.stopVid();
			break;														//break the loop
		}
	}

	return 0;
}