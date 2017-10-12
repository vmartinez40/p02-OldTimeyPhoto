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
    string filename;   
    // Read and convert image to pixels
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;

    //Ask user for file name
    cout<<"Please enter your file name that you want to turn OLd Timey!"<<endl;
    cin>>filename;

    //Store users file
    
    // Opens image
    image.open(filename);
    bmp = image.toPixelMatrix();
    cout<<"machupicchu.bmp has been loaded"<<endl;

    // Get values of height and width of image
    imageHeight = bmp.size(); //height?
    imageWidth = bmp[0].size(); //width
    cout<<"HEIGHT = "<<imageWidth<<endl;
    cout<<"WIDTH = "<<imageHeight<<endl;

    //Goes thorugh all the pixels
    for(int r=0; r<bmp.size(); r++)
    {
        for(int c=0; c<bmp[r].size(); c++)
        {
            rgb = bmp [r][c];
            //convert to b/w
            bmp[r][c]=rgb;
        }
    }


    return 0;
}
