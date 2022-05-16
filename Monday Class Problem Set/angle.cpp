#include "angle.h" // Includes angle class
using namespace std;


 
// Normalizes an angle so it is not greater than one revolution.
double Angle::normalize(double aRadians) const
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

// Displays the angle with a precision of one.
void Angle::display() const
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);
   cout << "Angle in Degrees: " << convertToDegrees(aRadians) << endl << endl;
}