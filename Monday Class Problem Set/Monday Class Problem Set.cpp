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

      aDegrees = aDegrees % 360.0;
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
      this->aRadians = convertToRadians(aDegrees);
   }

   void setRadians(double aRadians)
   {
      this->aRadians = aRadians;
   }

   void display() const
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);
      cout << "Angle in Degrees: " << convertToDegrees(aRadians) << endl;
   }
};


int main()
{

}