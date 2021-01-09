#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      fprintf(stderr, "Supply exactly one "
         "argument\n");
      return 1;
   }
   char buf[10] = { 0 };
   strncat(buf, argv[1], sizeof(buf)-1);
   printf("Test: %s\n", buf);
   return 0;
}
