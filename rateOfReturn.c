#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * This program will evaluate the annualized rate of return
 */

int main(int argc, char **argv) {

  double initialValue, finalValue, totalYears, weeksInYears, daysInYears, rateOfReturn,
         rateOfReturnPercent;
  int years, weeks, days;

  printf("Please input the Initial Value of investment: ");
  scanf("%lf", &initialValue);

  printf("Please input the Final Value of investment: ");
  scanf("%lf", &finalValue);

  printf("Please input the amount of years the investment took: ");
  scanf("%d", &years);

  printf("Please input the amount of weeks the investment took: ");
  scanf("%d", &weeks);

  printf("Please input the amount of days the investment took: ");
  scanf("%d", &days);

  printf("Initial Value is: %.6f dollars\n", initialValue);
  printf("Final Value is: %.6f dollars\n", finalValue);
  printf("number of years inputted is: %d\n", years);
  printf("number of weeks inputted is: %d\n", weeks);
  printf("number of days inputted is: %d\n", days);

  //making sure not to have zero starting value or negative money
  if (initialValue <= 0) {
    printf("Invalid initial value must be greater than 0 and non negative you gave: %.6f\n",
        initialValue);
    return 0;
  }

  //making sure that the money increased in value and that it didn't decrease
  if (initialValue > finalValue) {
    printf("Invalid input final value must be greater than initial value");
    return 0;
  }

  //converting weeks into years
  weeksInYears = (float) (weeks * 7.0 / 365.0);
  printf("Weeks is: %f\n", weeksInYears);

  //converting days into years
  daysInYears = (float) (days / 365.0);
  printf("Days is: %f\n", daysInYears);

  if (years < 0) {
    printf("Can't have negative time");
  }

  if (weeks < 0) {
    printf("Can't have negative time");
  }

  if (days < 0) {
    printf("Can't have negative time");

  }

  totalYears = years + weeksInYears + daysInYears;
  printf("Years is: %f\n", totalYears);

  if (totalYears <= 0) {
    printf("Can't have time equal to zero or negative time\n");
    }

  rateOfReturn = pow((finalValue/initialValue), (1 / totalYears) ) - 1;
  rateOfReturnPercent = rateOfReturn * 100;

  printf("Your annualized rate of return is: %f\n", rateOfReturnPercent);

  //making sure not to have an extreme index
//  if (index2 < 1) {
//    printf("Though theoretically possible, we don't accept indexes <1: %.f\n", index2);
//    return 0;
//  }

  //check to make sure the information falls into the valid range of angles
//  theta2 = asin ( ( (n1 * sin(theta1rad) ) / index2 ) ) * (180.0 / pi) ;
//  printf("Angle of refraction: %.10lf degrees\n", theta2);

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
