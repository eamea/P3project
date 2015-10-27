#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"

using namespace std;
using namespace cv;

int main()
{

	Detector dt(140, 5); //instantiating a new Detector object

	VideoCapture stream(0);

	Mat capturedFrame;
	Mat output;

	dt.createTrackbars();

	while (true){
		stream.read(capturedFrame);

		output = dt.segmentFrame(capturedFrame);

		imshow("Output", output);

		if (waitKey(30) == 27)
			break;
	}

	return 0;
}