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
    const int MAX_COLOUR = 255;

    cout << "Image size : " << IMAGE_W << " x " << IMAGE_H << endl;
    //Fetches colour values of each pixel and prints them
    for(int y = 0; y<IMAGE_H; y++){
        for(int x = 0; x<IMAGE_W; x++){
            ColorRGB colour = image.pixelColor(x, y);

            double red = colour.red() * MAX_COLOUR;
            double blue = colour.blue() * MAX_COLOUR;
            double green = colour.green() * MAX_COLOUR;



            cout << " Red is : " << red << " Blue is : " << blue << " Green is : " << green << endl;


        }
    }


  }
  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
  return 0;
}
