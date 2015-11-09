#include "BLOBDetector.h"

//Constructor
BLOBDetector::BLOBDetector(){

}

//Goes through each row and column and adds the grassfire algoritm. 
Mat BLOBDetector::BLOBDetection(Mat img, char color){
	BLOB = Mat::zeros(img.rows, img.cols, CV_8UC1);	//Sets the default BLOB image to be a black, empty image.

	switch (color){	//Resets a BLOB image based on the color-char parsed.
	case 'b':
		blueBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'g':
		greenBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'r':
		redBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'y':
		yellowBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	default:
		cout << "ERROR: BLOBDetection has not been parsed a valid color char." << endl;
		break;
	}
	
	for (size_t row = 0; row < img.rows; row++){	//runs the grassFire algorithm on the relevant image.
		for (size_t col = 0; col < img.cols; col++){
			if (img.at<unsigned char>(row, col) == 255){
				/*grassFire(row, col, img, color);
				object = object + 1;*/
				seqGrassFire(row, col, img, color); //calling seqGrassFire on the first object pixel we hit
				while (!xCoor.empty() && !yCoor.empty()){ //during seqGrassFire, neighboring object pixels have been added to lists xCoor & yCoor.
					seqGrassFire(xCoor.front(), yCoor.front(), img, color); //calling seqGrassFire on the first element in the lists.
					xCoor.pop_front(); //removing the element from the list
					yCoor.pop_front(); //removing the element from the list
				}
				object += 1; //increasing label by 1
			}
		}
	}

	switch (color){	//returns the analyzed image.
	case 'b':
		return blueBLOBImg;
	case 'g':
		return greenBLOBImg;
	case 'r':
		return redBLOBImg;
	case 'y':
		return yellowBLOBImg;
	default:
		cout << "ERROR: BLOBDetection has not been parsed a valid color char." << endl;
		return BLOB;
	}
}

void BLOBDetector::seqGrassFire(size_t row, size_t col, Mat img, char color){	//experimental
	img.at<uchar>(row, col) = 0; //burns the current pixel
	objectPixelIn(row, col, color);	//setting the pixel in output image to an object pixel
	if (col < img.cols - 1){
		if (img.at<unsigned char>(row, col + 1) == 255){						//checks the pixel to the right
			img.at<uchar>(row, col + 1) = 0; //burns the pixel in the input image
			objectPixelIn(row, col + 1, color); //setting the pixel in output image to an object pixel
			xCoor.push_back(row); //adding this pixel's x-coordinate to the end of the list
			yCoor.push_back(col+1); //adding this pixel's y-coordinate to the end of the list
		}
	}
	if (row < img.rows - 1 && col < img.cols - 1){
		if (img.at<unsigned char>(row + 1, col + 1) == 255){//checks the pixel to the right and down
			img.at<uchar>(row + 1, col + 1) = 0;
			objectPixelIn(row + 1, col + 1, color);
			xCoor.push_back(row + 1);
			yCoor.push_back(col + 1);
		}
	}
	if (row < img.rows - 1){
		if (img.at<unsigned char>(row + 1, col) == 255){						//checks the pixel below
			img.at<uchar>(row + 1, col) = 0;
			objectPixelIn(row + 1, col, color);
			xCoor.push_back(row + 1);
			yCoor.push_back(col);
		}
	}
	if (row < img.rows - 1 && col > 0){
		if (img.at<unsigned char>(row + 1, col - 1) == 255){			//checks the pixel below and to the left
			img.at<uchar>(row + 1, col - 1) = 0;
			objectPixelIn(row + 1, col - 1, color);
			xCoor.push_back(row + 1);
			yCoor.push_back(col - 1);
		}
	}
	if (col > 0){
		if (img.at<unsigned char>(row, col - 1) == 255){									//checks the pixel to the left
			img.at<uchar>(row, col - 1) = 0;
			objectPixelIn(row, col - 1, color);
			xCoor.push_back(row);
			yCoor.push_back(col - 1);
		}
	}
	if (row > 0 && col > 0){
		if (img.at<unsigned char>(row - 1, col - 1) == 255){					//checks the pixel up and to the left
			img.at<uchar>(row - 1, col - 1) = 0;
			objectPixelIn(row - 1, col - 1, color);
			xCoor.push_back(row - 1);
			yCoor.push_back(col - 1);
		}
	}
	if (row > 0){
		if (img.at<unsigned char>(row - 1, col) == 255){									//checks the pixel above
			img.at<uchar>(row - 1, col) = 0;
			objectPixelIn(row - 1, col, color);
			xCoor.push_back(row - 1);
			yCoor.push_back(col);
		}
	}
	if (row > 0 && col < img.cols - 1){
		if (img.at<unsigned char>(row - 1, col + 1) == 255){//checks the pixel above and to the right
			img.at<uchar>(row - 1, col + 1) = 0;
			objectPixelIn(row - 1, col + 1, color);
			xCoor.push_back(row - 1);
			yCoor.push_back(col + 1);
		}
	}
}

//Checks whether the neighboring pixels are white. Burns the current pixel by setting it to 0.
//void BLOBDetector::grassFire(size_t row, size_t col, Mat img, char color){
//	img.at<unsigned char>(row, col) = 0;	//burning the pixel
//
//	switch (color){	//setting the current pixel to the object color.
//	case 'b':
//		blueBLOBImg.at<unsigned char>(row, col) = object;
//		break;
//	case 'g':
//		greenBLOBImg.at<unsigned char>(row, col) = object;
//		break;
//	case 'r':
//		redBLOBImg.at<unsigned char>(row, col) = object;
//		break;
//	case 'y':
//		yellowBLOBImg.at<unsigned char>(row, col) = object;
//		break;
//	default:
//		break;
//	}
//
//	//NOTICE: when looking for "col + 1", it only works if the if-statement has "col > img.cols-1", for some reason. We don't know why.
//	if (col < img.cols-1 && img.at<unsigned char>(row, col + 1) == 255){						//checks the pixel to the right
//		grassFire(row, col + 1, img, color);
//	}
//	if (row < img.rows-1 && col < img.cols-1 && img.at<unsigned char>(row + 1, col + 1) == 255){//checks the pixel to the right and down
//		grassFire(row + 1, col + 1, img, color);
//	}
//	if (row < img.rows-1 && img.at<unsigned char>(row + 1, col) == 255){						//checks the pixel below
//		grassFire(row + 1, col, img, color);
//	}
//	if (row < img.rows-1 && col > 0 && img.at<unsigned char>(row + 1, col - 1) == 255){			//checks the pixel below and to the left
//		grassFire(row + 1, col - 1, img, color);
//	}
//	if (col > 0 && img.at<unsigned char>(row, col - 1) == 255){									//checks the pixel to the left
//		grassFire(row, col - 1, img, color);
//	}
//	if (row > 0 && col > 0 && img.at<unsigned char>(row -1, col - 1) == 255){					//checks the pixel up and to the left
//		grassFire(row - 1, col - 1, img, color);
//	}
//	if (row > 0 && img.at<unsigned char>(row - 1, col) == 255){									//checks the pixel above
//		grassFire(row - 1, col, img, color);
//	}
//	if (row < img.rows-1 && col < img.cols-1 && img.at<unsigned char>(row - 1, col + 1) == 255){//checks the pixel above and to the right
//		grassFire(row - 1, col + 1, img, color);
//	}
//}

void BLOBDetector::objectPixelIn(size_t row, size_t col, char color){
	switch (color){	//setting the current pixel to the object color.
	case 'b':
		blueBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'g':
		greenBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'r':
		redBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'y':
		yellowBLOBImg.at<unsigned char>(row, col) = object;
		break;
	default:
		break;
	}
}