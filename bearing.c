#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/** This program takes the latitude and longitude pair
  * for two bearinngs and computes the angle between
  * them
  */

int main(int argc, char **argv) {

  double latitude1, latitude1rad, longitude1, longitude1rad, latitude2, latitude2rad, longitude2,
         longitude2rad, deltarad, theta, thetarad;
  const double pi = 3.14159265359;

  printf("Input a latitude/longitude pair for the first position\n");
  scanf("%lf, %lf", &latitude1, &longitude1);
  printf("%lf, %lf\n", latitude1, longitude1);

  if (latitude1 < -180 || latitude1 > 180) {
    printf("latitude1 not in valid angle range you inputted: %lf\n", latitude1);
    return 0;
  }
  if (longitude1 < -180 || longitude1 >180) {
    printf("longitude1 not in valid angle range you inputted: %lf\n", longitude1);
    return 0;
  }

  printf("Input a latitude/longitude pair for the second position\n");
  scanf("%lf, %lf", &latitude2, &longitude2);
  printf("%lf, %lf\n", latitude2, longitude2);

  if (latitude2 < -180 || latitude2 > 180) {
    printf("latitude2 not in valid angle range you inputted: %lf\n", latitude2);
    return 0;
  }
  if (longitude2 < -180 || longitude2 > 180) {
    printf("longitude2 not in valid angle range you inputted: %lf\n", longitude2);
    return 0;
  }

  latitude1rad = latitude1 * (pi / 180.0);
  printf("latitude1 in radians is: %lf\n", latitude1rad);

  longitude1rad = longitude1 * (pi / 180.0);
  printf("longitude1 in radians is: %lf\n", longitude1rad);

  latitude2rad = latitude2 * (pi / 180.0);
  printf("latitude2 in radians is: %lf\n", latitude2rad);

  longitude2rad = longitude2 * (pi / 180.0);
  printf("longitude2 in radians is: %lf\n", longitude2rad);

  deltarad = longitude2rad - longitude1rad;
  printf("delta in radians is: %lf \n", deltarad);

  thetarad = atan2(sin(deltarad) * cos(latitude2rad), cos(latitude1rad) * sin(latitude2rad) -
      sin(latitude1rad) * cos(latitude2rad) * cos(deltarad) );
  printf("bearing is: %lf radians\n", thetarad);

  theta = thetarad * (180.0 / pi);
  printf("bearing is: %lf degrees\n", theta);

  return 0;
}
