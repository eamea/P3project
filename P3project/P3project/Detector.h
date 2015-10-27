#pragma once
class Detector
{
public:
	Detector(int tVal, int kSize);
	Mat segmentFrame(Mat src);
private:
	int thresholdValue;
	int kernelSize;
};

