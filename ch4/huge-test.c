#include <stdio.h>
#include <math.h>

int main(void)
{
   int number = 9999;
   double answer;
   if ( (answer = pow(number, number)) == HUGE_VAL )
   {
      fprintf(stderr, "A huge value\n");
      return 1;
   }
   else
   {
      printf("%lf\n", answer);
   }
   return 0;
}
