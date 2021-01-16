#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int ch; /* for each character */
   FILE *fp; /* pointer to a file stream */
   if ( argc < 3 || argc > 4 )
   {
      fprintf(stderr, "Usage: %s [path] [from pos]"
         " [to pos]\n", argv[0]);
      return 1;
   }
 
   /* open file with read mode */
   if ( (fp = fopen(argv[1], "r")) == NULL )
   {
      perror("Can't open file for reading");
      return 1;
   } 
    
   fseek(fp, atoi(argv[2]), SEEK_SET);
   /* loop over each line and write it to stdout */
   while( (ch = fgetc(fp)) != EOF )
   {
      if ( argv[3] != NULL)
      {
         if ( ftell(fp) >= atoi(argv[3]) )
         {
            break;
         }
      }
      putchar(ch);
   }
   printf("\n");
   fclose(fp); /* close the stream */
   return 0;
}
