#include <Magick++.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace Magick;
int main(int argc,char **argv)
{
  InitializeMagick(*argv);

  // Construct the image object. Seperating image construction from the
  // the read operation ensures that a failure to read the image file
  // doesn't render the image object useless.
  Image image;
  try {
    // Read a file into image object
    image.read( "ascii-pineapple.jpg" );

    cout << "Image Loaded" << endl;

    //Get width and height, get maximum RGB value
    const int IMAGE_W = image.rows();
    const int IMAGE_H = image.columns();
    const unsigned char MAX_COLOUR = 255;

    cout << "Image size : " << IMAGE_W << " x " << IMAGE_H << endl;
    //Fetches colour values of each pixel and prints them
    cout << "Iterating through brightness" << endl;
    for(int y = 0; y<IMAGE_W; y++){
        for(int x = 0; x<IMAGE_H; x++){
            ColorRGB colour = image.pixelColor(x, y);
             // Proper RGB values
             unsigned char red = colour.red() * MAX_COLOUR;
             unsigned char green = colour.green() * MAX_COLOUR;
             unsigned char blue = colour.blue() * MAX_COLOUR;
                // Brightness algorithm and scaling to ASCII mapping
             unsigned char brightness = (red + green + blue)/3;
             unsigned char ascii_scaling = brightness/3;

             //ASCII printing
             switch(ascii_scaling){
             case 0 ... 20:
             cout << '`';
             break;
             case 21 ... 40:
             cout << '^';
             break;
             case 41 ... 60:
             cout << '/';
             break;
             case 61 ... 80:
             cout << ",";
             break;


             default:
                 cout << ':';

             }


        }
        //New line each y change
             cout << endl;
    }


  }
  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
  return 0;
}
