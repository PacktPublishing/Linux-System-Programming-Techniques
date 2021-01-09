#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159

int main(void)
{
   char radius[20] = { 0 };

   while(fgets(radius, sizeof(radius), stdin) 
      != NULL)
   {
      /* Check if radius is numeric 
       * (and do conversion) */
      if( strspn(radius,"0123456789.\n") == 
         strlen(radius) )
      {
         printf("%.5f\n", PI*(atof(radius)*2) );
      }
      /* If radius is NOT numeric, print error 
       * and return */
      else
      {
         fprintf(stderr, "Found non-numeric "
            "value\n");
         return 1;
      }
   }
   return 0;
}
