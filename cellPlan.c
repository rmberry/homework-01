#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/** This program takes a data limit and amount of data used
  * accompanied by the current day in the plan and tells the user
  * what to do to keep on track and finish with no data left
  * since there is no rollover on the plan
  */

int main(int argc, char **argv) {

  double g, u, averageDailyUsed, averageDailyUseAllowed, exceedValue, correctionExceed,
         subceedValue, correctionSubceed;
  int d, dLeft;

  printf("Input a number of GB in the plan for 30 day period\n");
  scanf("%lf", &g);
  printf("%lf\n", g);

  if (g <= 0) {
    printf("Input number of GB in 30 day plan cannot be 0 or negative you inputted: lf\n", g);
    return 0;
  }

  printf("Input what the current day in to your 30 day period you are\n");
  scanf("%d", &d);
  printf("%d\n", d);

  if (d < 1 || d > 30) { 
    printf("Current day can't be less than 1 or greater than 30 %d\n", d);
    return 0;
  }

  printf("Input number of GB used so far in your 30 day period\n");
  scanf("%lf", &u);
  printf("%lf\n", u);

  if (u >= g) { 
    printf("You have already used all your data or exceeded the limit\n");
    return 0;
  }

  dLeft = 30 - d;
  printf("You have used %d days and have %d days left\n", d, dLeft);

  averageDailyUsed = (double) (u / d);
  averageDailyUseAllowed = (double) (g / 30.0);

  if (averageDailyUsed > averageDailyUseAllowed) {
    exceedValue = (double) ((averageDailyUsed * 30.0) - g );
    printf("You are EXCEEDING your average daily use %lf continuing this high usage, you'll exceed your data plan by %lf\n", averageDailyUseAllowed, exceedValue);
    correctionExceed = (double) ((g - u) /dLeft );
    printf("To stay below your data limit use no more than %lf per day\n", correctionExceed);
    return 0;
  }
  else if (averageDailyUsed < averageDailyUseAllowed) {
    subceedValue = (double) (g - (averageDailyUsed * 30.0));
    printf("You are SUBCEEDING your average daily use %lf continuing this low usage, you'll subceed your data plan by %lf\n", averageDailyUseAllowed, subceedValue);
    correctionSubceed = (double) ((g - u) /dLeft );
    printf("To reach  your data limit use %lf per day\n", correctionSubceed);
    return 0;
  }
  else {
    printf("You are using the allowable average daily use, continuing to do so will let you end with exactly the right amount of data usage\n");
    return 0;
  }

  return 0;
}

