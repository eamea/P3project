#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "Recognizer.h"
#include "UIHandler.h"
#include "BLOBDetector.h"
#include "Bounder.h"

using namespace std;
using namespace cv;

//An array containing chars for the letters we are going to learn
char letters[] {'a', 'b', 'f', 'l', 's', 't'};

int main()
{
	Detector detector(5); //instantiating a new Detector object called detector
	Recognizer recognizer(detector); //instantiating a new Recognizer object called recognizer
	Bounder bounder;

	VideoCapture stream(1); //capturing a stream from webcam 0.

	Mat capturedFrame;		//a mat for holding the current frame
	Mat output;				//a mat for holding the processed frame

	Mat boundImage = Mat::zeros(1,1,CV_8UC3);

	//detector.createTrackbars();

	while (true){ //infinite loop for constant frame update.
		stream.read(capturedFrame);	//reading a frame from the stream

		//Thresholding for the chosen letter.
		detector.thresholdImageFor(capturedFrame, 'f');

		bounder.setInputImg(detector.getBlueThreshImg());	//updating the input image of the bounder

		boundImage = bounder.boundingBox(200);

		imshow("Bounding boxes", boundImage);

		//output = detector.segmentFrame(capturedFrame);
		//imshow("Thresholded", output);

		//Showing thresholded images.
		imshow("blue thresh", detector.getBlueThreshImg());
		//imshow("green thresh", detector.getGreenThreshImg());
		//imshow("red thresh", detector.getRedThreshImg());
		//imshow("yellow thresh", detector.getYellowThreshImg());

		//Setting the detector for the recognizer, and BLOB-analyzing for the chosen letter.
		recognizer.setDetector(detector);
		//recognizer.BLOBAnalyze('a');

		//Showing BLOB-analyzed images.
		//imshow("blue blob", recognizer.getBlueBLOBImg());
		//imshow("yellow blob", recognizer.getYellowBLOBImg());

		imshow("Original", capturedFrame);	//showing the original image

		//Checks every 30 ms if 'esc'-key has been pressed by user. If true, break the loop.
		if (waitKey(30) == 27)
			break;
	}

	return 0;
}