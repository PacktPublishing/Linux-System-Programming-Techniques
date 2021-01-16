#include <stdio.h>

int main(int argc, char *argv[])
{
   FILE *fp; /* pointer to a file stream */
   char linebuf[1024] = { 0 }; /* line buffer */

   if ( argc != 2 )
   {
      fprintf(stderr, "Usage: %s [path]\n", 
         argv[0]);
      return 1;
   }

   /* open file with write mode */
   if ( (fp = fopen(argv[1], "w")) == NULL )
   {
      perror("Can't open file for writing");
      return 1;
   } 
    
   /*loop over each line and write it to the file*/
   while(fgets(linebuf, sizeof(linebuf), stdin) 
      != NULL)
   {
      fprintf(fp, linebuf);
   }
   fclose(fp); /* close the stream */
   return 0;
}
