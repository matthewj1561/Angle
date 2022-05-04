#define _USE_MATH_DEFINES  //FOR math constants

#include <iostream>
#include <cmath>     // FOR math constants
using namespace std;

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
   {
      return (aRadians / (2.0 * M_PI)) * 360.0;
   }

   // Converts from Degrees to Radians
   double convertToRadians(double aDegrees) const
   {
      return (aDegrees / 360.0) * (2.0 * M_PI);
   }

public:
   // Normalizes an angle so it is not greater than one revolution.
   double normalize(double aRadians)
   {
      double aDegrees = convertToDegrees(aRadians);
      
      // fmod returns the remainder after dividing, then multiplies by 360.0
      aDegrees = fmod(aDegrees, 360.0);
      
      // Ensure the angle is positive.
      if (aDegrees < 0)
      {
         aDegrees += 360.0;
      }

      return convertToRadians(aDegrees);
   }


   // Returns angle in degrees.
   double getDegrees() const
   {
      return convertToDegrees(aRadians);
   }

   // Returns angle in radians.
   double getRadians() const
   {
      return aRadians;
   }
   
   // Sets the angle in degrees.
   void setDegrees(double aDegrees) 
   {
      this->aRadians = normalize(convertToRadians(aDegrees));
   }

   // Sets the angle in radians.
   void setRadians(double aRadians)
   {
      this->aRadians = normalize(aRadians);
   }

   // Displays the angle with a precision of one.
   void display() const
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);
      cout << "Angle in Degrees: " << convertToDegrees(aRadians) << endl << endl;
   }
};


int main()
{
   Angle angleTester1;

   cout << "Test Case: Degrees | Input: 255.0" << endl;
   angleTester1.setDegrees(255.0);
   angleTester1.display();

   cout << "Test Case: Get Methods " << endl;
   cout << "Current angle in radians value: " << angleTester1.getRadians() << endl;
   cout << "Current angle in degrees value: " << angleTester1.getDegrees() << endl << endl;

   cout << "Test Case: Negative | Input: -20.0" << endl;
   angleTester1.setDegrees(-20.0);
   angleTester1.display();

   cout << "Test Case: Greater than 360 | Input: 720.0" << endl;
   angleTester1.setDegrees(720.0);
   angleTester1.display();
  
   cout << "Test Case: Radians | Input: pi" << endl;
   angleTester1.setRadians(M_PI);
   angleTester1.display();

   cout << "Test Case: Radians Greater than 2pi | Input: 3pi" << endl;
   angleTester1.setRadians(3 * M_PI);
   angleTester1.display();

   cout << "Test Case: Negative Radians | Input: -4pi" << endl;
   angleTester1.setRadians(-4 * M_PI);
   angleTester1.display();

   cout << "Test Case: Normalize -5 Degrees | Input: -5 deg | Output: 355 deg" << endl;
   angleTester1.setDegrees(-5);
   angleTester1.setRadians(angleTester1.normalize(angleTester1.getRadians()));
   cout << "Normalized -5 deg: " << angleTester1.getDegrees() << " degrees" << endl << endl;

   // Set precision for normalize Test Cases to see pi.
   cout.precision(5);
   cout << "Test Case: Normalize Positive | Input: 3pi | Output: pi" << endl;
   cout << "Normalized 3pi: " << angleTester1.normalize(3.0 * M_PI) << endl << endl;

   cout << "Test Case: Normalize Negative | Input: -5pi | Output: pi" << endl;
   cout << "Normalized -5pi: " << angleTester1.normalize(-5.0 * M_PI) << endl << endl;
}