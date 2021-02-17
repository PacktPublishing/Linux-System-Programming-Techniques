#include <stdio.h>
#include <stdlib.h>
float area(float radius);

int main(int argc, char *argv[])
{
   float number;
   float answer;
   if (argc != 2)
   {
      fprintf(stderr, "Type the radius of a "
         "circle\n");
      return 1;
   }
   number = atof(argv[1]);
   answer = area(number);
   printf("The area of a circle with a radius of "
      "%.2f is %.2f\n", number, answer);
   return 0;
}

float area(float radius)
{
   static float pi = 3.14159;
   return pi*radius*radius;
}
