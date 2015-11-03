#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "Recognizer.h"
#include "UIHandler.h"
#include "BLOBDetector.h"

using namespace std;
using namespace cv;

//An array containing chars for the letters we are going to learn
char letters[] {'a', 'b', 'f', 'l', 's', 't'};

//Creating a Matrix to hold the thresholded images
Mat blueThreshImg;
Mat greenThreshImg;
//Mat pinkThreshImg; //this one is outcommented because its not used
Mat redThreshImg;
Mat yellowThreshImg;

//Getter functions for each thresholded image
Mat getBlueThreshImg(){
	return blueThreshImg;
}
Mat getGreenThreshImg(){
	return greenThreshImg;
}
/* Pink is not used 
Mat getPinkThreshImg(){
	return pinkThreshImg;
}
*/
Mat getRedThreshImg(){
	return redThreshImg;
}
Mat getYellowThreshImg(){
	return yellowThreshImg;
}

//Thresholds only the colors that are needed for the specific letter.
void thresholdImagesFor(Detector dt, Mat src, char x){
	switch (x){
	case 'a':
		dt.setThreshold('b');
		blueThreshImg = dt.segmentFrame(src);
		
		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;

	case 'b':
		dt.setThreshold('r');
		redThreshImg = dt.segmentFrame(src);

		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;
	
	case 'f':
		dt.setThreshold('b');
		blueThreshImg = dt.segmentFrame(src);

		dt.setThreshold('g');
		greenThreshImg = dt.segmentFrame(src);

		dt.setThreshold('r');
		redThreshImg = dt.segmentFrame(src);

		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;
	
	case 'l':
		dt.setThreshold('b');
		blueThreshImg = dt.segmentFrame(src);

		dt.setThreshold('r');
		redThreshImg = dt.segmentFrame(src);

		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;
	
	case 's':
		dt.setThreshold('b');
		blueThreshImg = dt.segmentFrame(src);

		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;
	
	case 't':
		dt.setThreshold('b');
		blueThreshImg = dt.segmentFrame(src);

		dt.setThreshold('y');
		yellowThreshImg = dt.segmentFrame(src);

		break;
	
	default:
		cout << "ERROR: thresholdImageFor has not been parsed a valid char." << endl;
		break;
	}
}

int main()
{
	Detector detector(5); //instantiating a new Detector object called detector
	Recognizer recognizer(); //instantiating a new Recognizer object called recognizer

	VideoCapture stream(0); //capturing a stream from webcam 0.

	Mat capturedFrame;		//a mat for holding the current frame
	Mat output;				//a mat for holding the processed frame

	//detector.setThreshold('y'); //setting threshold values to threshold blue

	//detector.createTrackbars();	//creating a window called trackbar

	while (true){ //infinite loop for constant frame update.
		stream.read(capturedFrame);	//reading a frame from the stream

		//thresholding the colors for the letter input, and saving them in their respective matrices
		thresholdImagesFor(detector, capturedFrame, 'a');

		imshow("Original", capturedFrame);	//showing the original image

		//Checks every 30 ms if 'esc'-key has been pressed by user. If true, break the loop.
		if (waitKey(30) == 27)
			break;
	}

	return 0;
}