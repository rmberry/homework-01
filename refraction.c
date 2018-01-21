#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * This program will evaluate the angle of refraction using Snell's Law.
 *
 * @see https://en.wikipedia.org/wiki/Snell%27s_law
 */

int main(int argc, char **argv) {

  //theta1rad is the user's input angle converted into radians
  double theta1, theta2, theta1rad, index2;
  double angle1, value2;

  //n1 is a placeholder for in the starting environment was different than air
  double n1 = 1.0;

  //the constant pi from mathematics
  const double pi = 3.14159265359;
//   printf("pi: %.10f\n", pi);  // prints 3.1415926536
//   printf("%.10f\n", 4.0 * atan(1.0));  // prints 3.1415926536

  printf("Please input the angle of incidence (in degrees): ");
  scanf("%lf", &theta1);

  printf("Please input the index of refraction of the medium: ");
  scanf("%lf", &index2);

//   theta1 = atof(argv[1]);
//   index2 = atof(argv[2]);
  printf("Angle of incidence: %.6f degrees\n", theta1);
  printf("Index of refraction: %.6f\n", index2);

  /* need to convert user's input in degrees to radians so
   * the math library can use it
   */
  theta1rad = (double) (theta1 * pi / 180.00000);
//   printf("theta1rad: %.6f\n", theta1rad);

  if (theta1 < -180 || theta1 > 180) {
    printf("Invalid angle (must be [-180, 180]) theta1: %.6f\n", theta1);
    return 1;
  }
  //making sure not to have an extreme index
  if (index2 < 1) {
    printf("Though theoretically possible, we don't accept indexes <1: %.f\n", index2);
    return 1;
  }

  //check to make sure the information falls into the valid range of angles
  theta2 = asin ( ( (n1 * sin(theta1rad) ) / index2 ) ) * (180.0 / pi) ;
  printf("Angle of refraction: %.10lf degrees\n", theta2);

//   angle1 = (double) (n1 * sin(theta1rad) / index2);
//   value2 = (double) (180.0 / pi);
//   theta2 = (double) (asin(angle1) * value2);
//   printf("Angle of refraction: %lf degrees\n", theta2);
//
//   angle1 = (n1 * sin(theta1rad) / index2);
//   value2 = (180.0 / pi);
//   theta2 = (asin(angle1) * value2);
//
//   printf("Angle of refraction: %.10f degrees\n", theta2);

  return 0;
}
