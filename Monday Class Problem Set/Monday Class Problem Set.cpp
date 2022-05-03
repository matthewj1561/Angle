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

   // Normalizes an angle so it is not greater than one revolution.
   double normalize(double aRadians)
   {
      double aDegrees = convertToDegrees(aRadians);
      
      // Using floor
      /*double degQuotient = aDegrees / 360.0;
      double floorQuotient = floor(degQuotient);
      double result = (degQuotient - floorQuotient) * 360.0;
      return convertToRadians(result);*/
      
      // Using fmod.
      aDegrees = fmod(aDegrees, 360.0);

      // Finish normalizing for negative values
      if (aDegrees < 0.0)
      {
        aDegrees = 360.0 + aDegrees;
      }
      return convertToRadians(aDegrees);
   }
public:


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

   // Sets the angle radians.
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
   // Run test cases
   Angle angleTester1;

   cout << "Test Case: Degrees | Input: 255.0" << endl;
   angleTester1.setDegrees(255.0);
   angleTester1.display();

   cout << "Test Case: Get Methods " << endl;
   cout << "Current angle in radians value: " << angleTester1.getRadians() << endl;
   cout << "Current angle in degrees value: " << angleTester1.getDegrees() << endl << endl;

   cout << "Test Case: Negative Degrees | Input: -20.0" << endl;
   angleTester1.setDegrees(-20.0);
   angleTester1.display();

   cout << "Test Case: Greater than 360 | Input: 630.0" << endl;
   angleTester1.setDegrees(630.0);
   angleTester1.display();
  
   cout << "Test Case: Radians | Input: pi" << endl;
   angleTester1.setRadians(M_PI);
   angleTester1.display();

   cout << "Test Case: Radians Greater than 2pi | Input: 3.5pi" << endl;
   angleTester1.setRadians(3.5 * M_PI);
   angleTester1.display();

   cout << "Test Case: Negative Radians | Input: -1.5pi" << endl;
   angleTester1.setRadians(-1.5 * M_PI);
   angleTester1.display();
   
}