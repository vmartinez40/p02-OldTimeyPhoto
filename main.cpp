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
    //Initialize image variables
    Bitmap image;
    Pixel rgb;
    vector <vector <Pixel> > bmp;
    string filename;
    

    //Ask user for file name
    cout<<"Please enter your file name that you want to turn OLd Timey!"<<endl;
    cin>>filename;
    
    // Opens image
    image.open(filename);
    bmp = image.toPixelMatrix();
    cout<<filename<<".bmp has been loaded"<<endl;
    
    //Check if file is in a bmp format
    bool validBmp = image.isImage();

    while(validBmp == true)
    {
    //Goes thorugh all the pixels and converts to greyscale
        for(int r=0; r<bmp.size(); r++)
        {
            for(int c = 0; c < bmp[0].size(); r++)
            {          
                int avg = (rgb.red+rgb.green+rgb.blue)/3;
                rgb.red = avg;
                rgb.green = avg;
                rgb.blue = avg;
            }
        }
    }
    while(validBmp == false)
    {
        cout<<"The file is not in the correct format. Please make sure it is a BMP file."<<endl;
        main();
    }
    
    //Save the file as oldtimey.bmp
    image.fromPixelMatrix(bmp);
    image.save("OldTimeyPhoto.bmp");
    cout<<"Your image was turned OldTimey"<<endl;
    return 0;
}
