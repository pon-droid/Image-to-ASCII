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
    image.read( "source.jpg" );

    cout << "Image Loaded" << endl;

    //Get width and height, get maximum RGB value
    const unsigned char MAX_COLOUR = 255;
    // Define ASCII chars in order from least 'bright' to most 'bright'
    char characters[] = {96,94,92,34,44,58,59,73,108,33,105,126,43,95,45,63,93,91,125,123,49,41,40,124,92,92,47,116,102,106,114,120,110,117,118,99,122,88,89,85,74,67,76,81,48,79,90,109,119,113,112,100,98,107,104,97,111,42,35,77,87,38,56,37,66,64,36};
    Geometry newsize = Geometry(300,300);
    //Resize image for better image quality

    image.resize(newsize);
    const int IMAGE_W = image.rows();
    const int IMAGE_H = image.columns();
    image.display();


    for(int y = 0; y<IMAGE_W; y++){
        for(int x = 0; x<IMAGE_H; x++){
            ColorRGB colour = image.pixelColor(x, y);
             // Proper RGB values
             unsigned char red = colour.red() * MAX_COLOUR;
             unsigned char green = colour.green() * MAX_COLOUR;
             unsigned char blue = colour.blue() * MAX_COLOUR;
                // Brightness algorithm and scaling to ASCII mapping
             unsigned char brightness(0.2126*red + 0.7152*green + 0.0722*blue);
             unsigned char ascii_scaling = brightness/4;

             //ASCII printing
             cout << characters[ascii_scaling];
             cout << characters[ascii_scaling];
             cout << characters[ascii_scaling];



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
