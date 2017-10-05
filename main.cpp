/*
Victor Martinez's Old Timey Photo Program!

Program Requirements: 
    Ask the user for file name of an image(Must be BMP format)
    Convert the image so every pixel in it is grey scale (black, white, and shades of grey only) based on the original pixel colors
    Save the file as oldtimey.bmp

CSCI 111
Kevin Buffardi
Last Edited: 10/2/17
Due:10/16/17
*/

#include<iostream>
#include<vector>
#include<string>
#include"bitmap.h"

using namespace std;

int main()
{
    //Initialize image height and width
    int imageHeight,imageWidth;
    
    // Read and convert image to pixels
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;
    
    // Opens image
    image.open("machupicchu.bmp");
    bmp = image.toPixelMatrix();
    cout<<"machupicchu.bmp has been loaded"<<endl;

    // Get values of height and width of image
    imageHeight = bmp.size(); //height?
    imageWidth = bmp[0].size(); //width
    cout<<"HEIGHT = "<<imageWidth<<endl;
    cout<<"WIDTH = "<<imageHeight<<endl;

//Ask user for file name

//Store users file name 

    return 0;
}
