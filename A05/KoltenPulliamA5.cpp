//**************************************************************
// Assignment #5
// Name: Kolten Pulliam, Angel Badillo
// CMPS-5113-102 - Advanced Programming Language Concepts
// Date: 11/13/2023
//***************************************************************
// Description:
// This program demonstrated multiplying and dividing phasors
// using instances of the Phasor class. The Phasor class allows
// creating a Phasor with the default constructor, which simply
// creates a Phasor with a magnitude of 0, and phase of 0 degrees.
// Using the paramaterized constructor, a Phasor can be created
// by passing in the rectangular form (a complex number), and the
// magnitude and phase are calculated from the rectangular form.
// The implemented overloaded multiplication and division operators
// allow multiplying and dividing instances of Phasors, and returning
// the result as an instance of a Phasor.
//
// Compilation Instructions:
// g++ KoltenPulliamA5.cpp -o main
//
// Execution Instructions:
// ./main
//
//*****************************************************************
#include <cmath>
#include <iostream>
#include <iomanip>
#define BLANK_LINE "\n\n"

using namespace std;

class Phasor
{
private:
    double magnitude{0};
    double phase{0};

public:
    //*******************************************************************
    // Phasor::Phasor()
    // Parameters: None
    // The default constructor that sets all member variables to zero by
    // default.
    // Returns: None
    //********************************************************************
    Phasor();

    //*******************************************************************
    // Phasor::Phasor(double, double)
    // Parameters:
    // double a - The real component of a complex number.
    // double bi - The imaginary component of a complex number.
    // The parameterized constructor that initializes the member variables
    // to the parameters given.
    // Returns: None
    //********************************************************************
    Phasor(double a, double bi);

    //*******************************************************************
    // Phasor::~Phasor()
    // Parameters: None
    // The deconstructor to execute any functionality that needs to run
    // upon the end of the life of the current instance of the class.
    // Returns: None
    //********************************************************************
    ~Phasor();

    //*******************************************************************
    // Phasor::setMagnitude(double)
    // Parameters:
    // double newMagnitude - The new value to assign to 'magnitude'
    // The setter method to assign a new value to the 'magnitude' member
    // variable.
    // Returns: None
    //********************************************************************
    void setMagnitude(double newMagnitude);

    //*******************************************************************
    // Phasor::setPhase(double)
    // Parameters:
    // double newPhase - The new value to assign to 'phase'
    // The setter method to assign a new value to the 'phase' member
    // variable.
    // Returns: None
    //********************************************************************
    void setPhase(double newPhase);

    //*******************************************************************
    // Phasor::getMagnitude()
    // Parameters: None
    // The getter method to retrieve the 'magnitude' member variable.
    // Returns: double - the magnitude of the Phasor.
    //********************************************************************
    double getMagnitude();

    //*******************************************************************
    // Phasor::getPhase()
    // Parameters: None
    // The getter method to retrieve the 'phase' member variable.
    // Returns: double - the phase of the Phasor.
    //********************************************************************
    double getPhase();

    //*******************************************************************
    // Phasor::operator*()
    // Parameters:
    // const Phasor& other - The phasor instance on the right hand side
    // The operator overload for the multiplication operator to allow for
    // multiplication between two phasors.
    // Returns: Phasor - A Phasor instance with the stored result.
    //********************************************************************
    Phasor operator*(const Phasor &other) const;

    //*******************************************************************
    // FOR ALL FUNCTIONS function Name::MethodName()
    // Parameters: List them here and comment
    // The operator overload for the division operator to allow for
    // division between two phasors.
    // Returns: Phasor - A Phasor instance with the stored result.
    //********************************************************************
    Phasor operator/(const Phasor &other) const;
};

Phasor::Phasor() {}

Phasor::~Phasor() {}

void Phasor::setMagnitude(double newMagnitude)
{
    this->magnitude = newMagnitude;
}

void Phasor::setPhase(double newPhase)
{
    // Ensures the value is a postive angle
    while (newPhase < 0)
    {
        newPhase += 360;
    }
    this->phase = newPhase;
}

double Phasor::getMagnitude()
{
    return this->magnitude;
}

double Phasor::getPhase()
{
    return this->phase;
}

Phasor::Phasor(double a, double bi)
{
    // Calculates the magnitude from the rectangular form, a + bi
    // Magnitude = sqrt(a^2 + b^2)
    this->magnitude = sqrt((a * a + bi * bi));

    // Calculates the phase from the rectangular form, a + bi
    // Phase = arctan(b / i)
    double tempPhase = atan(bi / a) * (180.0 / M_PI);

    // Convert angle to positive angle, if negative
    while (tempPhase < 0)
    {
        tempPhase += 360;
    }

    this->phase = tempPhase;
}

Phasor Phasor::operator*(const Phasor &other) const
{
    Phasor result;
    result.magnitude = this->magnitude * other.magnitude;
    result.phase = this->phase + other.phase;

    // Ensures the value stays between 0 and 360
    if (result.phase > 360)
    {
        result.phase -= 360;
    }

    return result;
}

Phasor Phasor::operator/(const Phasor &other) const
{
    Phasor result;
    result.magnitude = this->magnitude / other.magnitude;
    result.phase = this->phase - other.phase;

    // Ensures the value is a postive angle
    while (result.phase < 0)
    {
        result.phase += 360;
    }

    return result;
}

int main()
{
    // Create three new phasors using the default constructor
    Phasor A, D, E;

    // Create two new phasors using the parameterized constructor
    Phasor B(sqrt(2), -sqrt(2));
    Phasor C(sqrt(2), sqrt(3));

    A.setMagnitude(3);
    A.setPhase(-45);

    D = B * C;
    E = B / C;

    cout << "================================="
         << "\n";
    cout << "This is A\n";
    cout << "Magnitude: " << left << setw(9) << A.getMagnitude() << right << "Phase: " << A.getPhase() << "\n";
    cout << "================================="
         << "\n";
    cout << "This is B\n";
    cout << "Magnitude: " << left << setw(9) << B.getMagnitude() << right << "\tPhase: " << B.getPhase() << "\n";
    cout << "================================="
         << "\n";
    cout << "This is C\n";
    cout << "Magnitude: " << left << setw(9) << C.getMagnitude() << right << "\tPhase: " << C.getPhase() << "\n";
    cout << "================================="
         << "\n";
    cout << "This is D = B * C\n";
    cout << "Magnitude: " << left << setw(9) << D.getMagnitude() << right << "\tPhase: " << D.getPhase() << "\n";
    cout << "================================="
         << "\n";
    cout << "This is E = B / C\n";
    cout << "Magnitude: " << left << setw(9) << E.getMagnitude() << right << "\tPhase: " << E.getPhase() << "\n";

    return 0;
}