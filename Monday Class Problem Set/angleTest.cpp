#include "angle.h"
#include <iostream>

using namespace std;

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