#include "BLOBDetector.h"

//Constructor
BLOBDetector::BLOBDetector(){

}

//Goes through each row and column and adds the grassfire algoritm. 
Mat BLOBDetector::BLOBDetection(Mat img){
	for (size_t row = 0; row < img.rows; row++){
		for (size_t col = 0; col < img.cols; col++){
			if (img.at<unsigned char>(row, col) == 255){
				grassFire(row, col);
				object = object + 1;
			}
		}
	}

	return BLOB;
}

//Checks whether the neighboring pixels are white. Burns the current pixel to set it to 0.
void BLOBDetector::grassFire(size_t row, size_t col){
	img.at<unsigned char>(row, col) = 0;
	BLOB.at<unsigned char>(row, col) = object;
	if (img.at<unsigned char>(row, col + 1) == 255){			//checks the Pixel to the right
		grassFire(row, col + 1);
	}
	if (img.at<unsigned char>(row + 1, col + 1) == 255){		//checks the Pixel to the right and down
		grassFire(row + 1, col + 1);
	}
	if (img.at<unsigned char>(row + 1, col) == 255){			//checks the Pixel below
		grassFire(row + 1, col);
	}
	if (img.at<unsigned char>(row + 1, col - 1) == 255){		//checks the Pixel below and to the left
		grassFire(row + 1, col - 1);
	}
	if (img.at<unsigned char>(row, col - 1) == 255){			//checks the Pixel to the left
		grassFire(row, col - 1);
	}
	if (img.at<unsigned char>(row -1, col - 1) == 255){			//checks the Pixel up and to the left
		grassFire(row - 1, col - 1);
	}
	if (img.at<unsigned char>(row - 1, col) == 255){			//checks the Pixel above
		grassFire(row - 1, col);
	}
	if (img.at<unsigned char>(row + 1, col - 1) == 255){		//checks the Pixel above and to the right
		grassFire(row + 1, col - 1);
	}
}

//Returns the BLOB image.
//Mat BLOBDetector::returnBLOB(){
//	return BLOB;
//}

