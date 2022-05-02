#define _USE_MATH_DEFINES  //FOR math constants

#include <iostream>
#include <cmath>     // FOR math constants
using namespace std;

/**********
class Grade
{
private:
   double grade;

public:
   void set(double value)
   {
      if (0.0 <= value && value <= 100.0)
      {
         grade = value;
      };
   }

   double get() const
   {
      return this->grade;
   }

   void display() const
   {
      // The "|" is a Binary OR.
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);

      cout << "Grade: " << grade << "%" << endl;
   }

};
*************************************************/


class Angle
{
private:
   double aRadians;

   // comment
   double convertToDegrees(double aRadians) const
   {
      return (aRadians / (2.0 * M_PI)) * 360.0;
   }

   double convertToRadians(double aDegrees) const
   {
      return (aDegrees / 360.0) * (2.0 * M_PI);
   }

   double normalize(double aRadians)
   {
      double aDegrees = convertToDegrees(aRadians);

      aDegrees  = fmod(aDegrees, 360.0);
      
      return convertToRadians(aDegrees);
   }

public:
   double getDegrees() const
   {
      return convertToDegrees(aRadians);
   }

   double getRadians() const
   {
      return aRadians;
   }
   
   void setDegrees(double aDegrees) 
   {
      this->aRadians = normalize(convertToRadians(aDegrees));
   }

   void setRadians(double aRadians)
   {
      this->aRadians = normalize(aRadians);
   }

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
}