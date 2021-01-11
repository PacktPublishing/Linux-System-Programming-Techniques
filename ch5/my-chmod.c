#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void printUsage(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
   long int accessmode; /*To hold the access mode*/
   /* Check that the user supplied two arguments */
   if (argc != 3)
   {
      printUsage(stderr, argv[0]);
      return 1;
   }
   /* Simple check for octal numbers and 
      correct length */
   if( strspn(argv[1], "01234567\n") 
         != strlen(argv[1]) 
         || ( strlen(argv[1]) != 3 && 
              strlen(argv[1]) != 4 ) )
   {
      printUsage(stderr, argv[0]);
      return 1;
   }
   /* Convert to octal and set the permissions */
   accessmode = strtol(argv[1], NULL, 8);
   if (chmod(argv[2], accessmode) == -1)
   {
      perror("Can't change permissions");
   }
   return 0;
}

void printUsage(FILE *stream, char progname[])
{
    fprintf(stream, "Usage: %s <numerical "
        "permissions> <path>\n", progname);
}
