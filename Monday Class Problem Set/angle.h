#define _USE_MATH_DEFINES  //FOR math constants

#include <iostream>
#include <cmath>     // FOR math constants


/*****************************************************************************
* ANGLE
* The angle class keeps track of angles, with the ability to convert between
* degrees and radians, display, normalize angles, and get and set the angle.
******************************************************************************/

class Angle
{
private:
   double aRadians;

   // Converts from Radians to Degrees
   double convertToDegrees(double aRadians) const
   { return (aRadians / (2.0 * M_PI)) * 360.0; }

   // Converts from Degrees to Radians
   double convertToRadians(double aDegrees) const
   { return (aDegrees / 360.0) * (2.0 * M_PI); }

   // Normalizes an angle so it is not greater than one revolution.
   double normalize(double aRadians) const;

public:


   // Returns angle in degrees.
   double getDegrees() const{ return convertToDegrees(aRadians); }

   // Returns angle in radians.
   double getRadians() const{ return aRadians; }

   // Sets the angle in degrees.
   void setDegrees(double aDegrees)
   { this->aRadians = normalize(convertToRadians(aDegrees)); }

   // Sets the angle radians.
   void setRadians(double aRadians){ this->aRadians = normalize(aRadians); }

   // Displays the angle with a precision of one.
   void display() const;
};


