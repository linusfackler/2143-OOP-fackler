///////////////////////////////////////////////////////////////////////////////
//
// Author:           Linus Fackler
// Email:            linus.fackler@iCloud.com
// Label:            A08
// Title:            Assignment 8 - CopyConstructor
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       In this program I rewrote the original code with an existing RgbColor
//       class so there is a ColorPalette that can store multiple instances
//       of RgbColor with a Vector. It has methods to add Colors to the vector,
//       as well as print them.
//
// Usage:
//       g++ main.cpp -o main
//       main
//
// Files:
//       main.cpp
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

using namespace std;


/**
 * This is an implementation of our single color rgb class.
 *
 */
class RgbColor{
    int r;                  //int 0-255 red
    int g;                  //int 0-255 green
    int b;                  //int 0-255 blue
public:
    RgbColor();             // default constructor
    RgbColor(int);          // overloaded 1
    RgbColor(int,int,int);  // overloaded 2

    void SetR(int);         // setter red
    void SetG(int);         // setter green
    void SetB(int);         // setter blue

    int GetR();             // getter red
    int GetG();             // getter green
    int GetB();             // getter blue

    void GrayScale();       // averages colors

    // print to stdout
    friend ostream& operator<<(ostream&,const RgbColor&);

    // add (mix) two colors
    RgbColor operator+(const RgbColor& );

};


// I changed this a little bit so the color values get stored in
// a temporary variable and then returned in a new RgbColor instance
// with the second overloaded constructor.
// In your original code, the returned one was the same as the first
// one in the addition
RgbColor RgbColor::operator+(const RgbColor& rhs){
    int tempR = (this->r + rhs.r) / 2;
    int tempG = (this->g + rhs.g) / 2;
    int tempB = (this->b + rhs.b) / 2;

    return RgbColor(tempR, tempG, tempB);
}


RgbColor::RgbColor(){
    r = g = b = 0;      // defaut constructor, rgb set to 0
}

RgbColor::RgbColor(int color){
    r = g = b = color;  // overloaded 1
}

RgbColor::RgbColor(int _r,int _g, int _b){
    r = _r;
    g = _g;             // overloaded 2
    b = _b;
}

ostream& operator<<(ostream& os,const RgbColor& rhs){
    os<<"["<<rhs.r<<","<<rhs.g<<","<<rhs.b<<"]";
    return os;
}



class ColorPalette: public RgbColor
{
    private:
        vector<RgbColor> palette;
            // vector to store RbgColor instances in

    public:
        ColorPalette()              // default constructor
        {
            palette.reserve(50);    // set size to 50
        }

        ColorPalette(int _size)     // overloaded constructor
        {
            palette.reserve(_size); // set size to passed in int
        }

        void addColor(RgbColor color);

        void printPalette();
};


/**
 * Description:
 *      this function adds an instance of an RgbColor to the
 *      Color Palette
 * Params:
 *      Instance of class RgbColor "color"
 *
 * Returns:
 *      Void, no return
 */
void ColorPalette::addColor(RgbColor color)
{
    palette.push_back(color);
}

/**
 * Description:
 *      prints all objects of the vector
 * Params:
 *      None
 * Returns:
 *      Void, no return
 */
void ColorPalette::printPalette()
{
    cout << "The colors in the palette are: ";

    for (int i = 0; i < palette.size() ; i++)
    {   // palette.size is the actual number of objects in vector
        cout << palette.at(i) << endl;
    }   // RgbColor at spot i is printed out
}


int main() {

    RgbColor Color1(255,200,11);
    RgbColor Color2(100,14,123);
    RgbColor Color3 = Color1 + Color2;

    ColorPalette pal;           // colorpalette created
    pal.addColor(Color1);       // added instance of RgbColor..
    pal.addColor(Color2);       // ..to instance of ColorPalette
    pal.addColor(Color3);

    pal.printPalette();         // printing ColorPalette
}
