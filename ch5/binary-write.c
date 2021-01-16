#include <stdio.h>

int main(void)
{
   FILE *fp;
   float x[2];
   if ( (fp = fopen("my-binary-file", "wb")) == 0 )
   {
      fprintf(stderr, "Can't open file for "
         "writing\n");
      return 1;
   }
   printf("Type two floating point numbers, "
      "separated by a space: ");
   scanf("%f %f", &x[0], &x[1]);
   fwrite(&x, sizeof(float), 
      sizeof(x) / sizeof(float), fp);
   fclose(fp);
   return 0;
}
