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

int main()
{
	Detector detector(5); //instantiating a new Detector object called detector
	Recognizer recognizer(detector); //instantiating a new Recognizer object called recognizer

	VideoCapture stream(0); //capturing a stream from webcam 0.

	Mat capturedFrame;		//a mat for holding the current frame
	Mat output;				//a mat for holding the processed frame

	//detector.setThreshold('y'); //setting threshold values to threshold blue

	//detector.createTrackbars();	//creating a window called trackbar

	while (true){ //infinite loop for constant frame update.
		stream.read(capturedFrame);	//reading a frame from the stream

		detector.thresholdImageFor(capturedFrame, 'a');

		imshow("blue thresh", detector.getBlueThreshImg());

		recognizer.setDetector(detector);

		recognizer.BLOBAnalyze('a');

		//imshow("original", capturedFrame);

		imshow("blue blob", recognizer.getBlueBLOBImg());

		//thresholding the colors for the letter input, and saving them in their respective matrices
		//thresholdImagesFor(detector, capturedFrame, 'a');

		//imshow("Original", capturedFrame);	//showing the original image

		//Checks every 30 ms if 'esc'-key has been pressed by user. If true, break the loop.
		if (waitKey(30) == 27)
			break;
	}

	return 0;
}