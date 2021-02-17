#include <stdio.h>

int main(void)
{
   int x;
   int y = 5;
   char text[20] = "Hello, world";
   for (x = 1; y < 100; x++)
   {
      y = (y*3)-x;
   }
   printf("%s\n", text);
   printf("y = %d\n", y);
   return 0;
}
