//**************************************************************
// Assignment #4
// Name: Kolten Pulliam
// Data Structures Date: 11/7/2023
//***************************************************************
// The following program showcases the functionality in the 
// "Marker" class. The class will have the ability to set its 
// ink level (in milimeters) and ink color. It will also have the
// ability to retrieve its current value for the ink level and 
// ink color.
//*****************************************************************
#include <iostream> 
#include <string>

#define BLANK_LINE "\n\n"

using namespace std;

class Marker
{
public:
    Marker();
    Marker(float inkLevel, string inkColor);
    ~Marker();

    void setInkLevel(float newInkLevel);
    void setInkColor(string newInkColor);
    
    float getInkLevel();
    string getInkColor();

private:
    float inkLevel;
    string inkColor;
};


//*******************************************************************
// Marker::Marker()
//
// Parameters: none
//
// The default constructor of the Marker class. Will set the initial
// values of 'inkLevel' and 'inkColor' member variables.
//********************************************************************
Marker::Marker()
{
    inkLevel = 0.f;
    inkColor = "Black";
}

//*******************************************************************
// Marker::Marker(float initInkLevel, string initInkColor)
//
// Parameters: 
// initInkLevel -> float
// - The initial floating point number to be used for inkLevel
// initInkColor -> string
// - The initial string to be used for inkColor
//
// The parameterized constructor of the Marker class. Will set the
// initial values of the 'inkLevel' and 'inkColor' member variables
// using the paramters given to it.
//********************************************************************
Marker::Marker(float initInkLevel, string initInkColor)
{
    inkLevel = initInkLevel;
    inkColor = initInkColor;
}

//*******************************************************************
// Marker::~Marker()
//
// Parameters: none
//
// The deconstructor for the Marker class. Will perform any 
// functionality defined when the instance of the class goes out of 
// scope or is deleted manually.
//********************************************************************
Marker::~Marker()
{

}

//*******************************************************************
// Marker::setInkLevel(float newInkLevel)
//
// Parameters: 
// newInkLevel -> float
// - The new value to assign to inkLevel
//
// This setter method will take the given parameter, and assign it to 
// 'inkLevel'.
//********************************************************************
void Marker::setInkLevel(float newInkLevel)
{
    inkLevel = newInkLevel;
}

//*******************************************************************
// Marker::setInkColor(string newInkColor)
//
// Parameters:
// string newInkColor
// - The new value to assign to inkColor
//
// This setter method will take the given parameter, and assign it to 
// 'inkColor'.
//********************************************************************
void Marker::setInkColor(string newInkColor)
{
    inkColor = newInkColor;
}

//*******************************************************************
// Marker::getInkLevel()
//
// Parameters: none
//
// This getter method will return the value that is stored within the
// 'inkLevel' member variable.
//********************************************************************
float Marker::getInkLevel()
{
    return inkLevel;
}

//*******************************************************************
// Marker::getInkColor()
//
// Parameters: none
//
// This getter method will return the value that is stored within the
// 'inkColor' member variable.
//********************************************************************
string Marker::getInkColor()
{
    return inkColor;
}

int main() {
    // Create a marker using the default constructor
    Marker m1;

    // Create a marker using the parameterized constructor
    Marker m2(2.2, "Red");

    // Print the current values of the two markers
    cout << "Marker 1:\nInk Level: " << m1.getInkLevel() << "\nInk Color: " << m1.getInkColor() << BLANK_LINE;
    cout << "Marker 2:\nInk Level: " << m2.getInkLevel() << "\nInk Color: " << m2.getInkColor() << BLANK_LINE;

    // Change the color of the ink for Marker 1
    m1.setInkColor("Yellow");
    cout << "Set 'Marker 1' color to 'Yellow'." << BLANK_LINE;

    // Print the current values of the two markers
    cout << "Marker 1:\nInk Level: " << m1.getInkLevel() << "\nInk Color: " << m1.getInkColor() << BLANK_LINE;
    cout << "Marker 2:\nInk Level: " << m2.getInkLevel() << "\nInk Color: " << m2.getInkColor() << "\n";

    return 0;
}