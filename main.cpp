/*
Victor Martinez's Old Timey Photo Program!

Program Requirements: 
    Ask the user for file name of an image(Must be BMP format)
    Convert the image so every pixel in it is grey scale (black, white, and shades of grey only) based on the original pixel colors
    Save the file as oldtimey.bmp

CSCI 111
Kevin Buffardi
Last Edited: 10/13/17
Due Date:10/16/17
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
    int imageHeight, imageWidth;
    

    //Ask user for file name
    bool validBmp = false;
    while (validBmp == false)
    {
        cout<<"Please enter your file name that you want to turn OLd Timey!"<<endl;
        cin>>filename;
    
        // Opens image
        image.open(filename);

        //Check if file is in a bmp format
        validBmp = image.isImage();
        if (validBmp == false)
        {
            cout<<"The file is not in the correct format. Please make sure it is a BMP file."<<endl;
        
        }
        else validBmp = true;
    }

    bmp = image.toPixelMatrix();
    cout<<filename<<" has been loaded"<<endl;

    //Check values for image H/W
    imageHeight = bmp.size();
    imageWidth = bmp[0].size();
    cout<<"Your image is "<<imageHeight<<" pixels high and "<<imageWidth<<" pixels wide!"<<endl;
    
    //Goes thorugh all the pixels and converts to greyscale
        for(int r = 0; r < bmp.size(); r++)
        {
            for(int c = 0; c < bmp[r].size(); c++)
            {   
                rgb = bmp[r][c];
                int avg = (rgb.red + rgb.green + rgb.blue)/3;
                rgb.red = avg;
                rgb.green = avg;
                rgb.blue = avg;
                bmp[r][c] = rgb;
            }
        }
        //Save the file as oldtimey.bmp
        image.fromPixelMatrix(bmp);
        image.save("OldTimeyPhoto.bmp");
        cout<<"Your image was turned OldTimey"<<endl;
    
    return 0;   
}
