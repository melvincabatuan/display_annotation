/*****************************************************************************************************
 
The MIT License (MIT)

Copyright (c) Melvin Cabatuan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

@melvincabatuan

 
 Software for displaying one annotation in a standard format, i.e. <filepath> <number_rectangles> <x1 y1 width1 height1 ... xn yn widthn heightn>.

USAGE

 ./display_annotation <filepath> <number_rectangles> <x1 y1 width1 height1 ... xn yn widthn heightn>
*****************************************************************************************************/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main( int argc, const char** argv )
{
    // If no parameters are give, then a usage template should be provided
     
    if(argc == 1){
	cout << "Software for defining average dimensions of a given set of annotations" << endl;
    cout << "USAGE ./display_annotation <filepath> <number_rectangles> <x1 y1 width1 height1 ... xn yn widthn heightn>" << endl;
    cout << "Ex. ./display_annotation /home/cobalt/Pictures/IMG_20160610_170847.jpg 1 101 338 123 153" << endl;
     	   return 0;
    }
 
    
     // Open image
     const string filepath = argv[1];
     cv::Mat current_image;
     current_image = cv::imread(filepath, cv::IMREAD_COLOR);
      
     if( current_image.empty() ) {                     // Check for invalid input    
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    
     // Extract rectangles
     int number_rectangles = atoi(argv[2]);
     vector<cv::Rect> rectangles;
     
     //cout << " number_rectangles = " << number_rectangles << endl;
     
 
     for (int i = 0; i < number_rectangles; i++){
     
        	cv::Rect single_rectangle = cv::Rect(atoi(argv[3+(i*4)]), atoi(argv[4+(i*4)]), atoi(argv[5+(i*4)]), atoi(argv[6+(i*4)])); 
        	
        	// Draw rectangles
     		cv::rectangle(current_image, single_rectangle, cv::Scalar(0,0,255), 5);
            rectangles.push_back(single_rectangle);
     }   
 
    
	 // Init window interface  
    cv::imshow(filepath, current_image);
    cv::waitKey(0);
    return 0;
}
