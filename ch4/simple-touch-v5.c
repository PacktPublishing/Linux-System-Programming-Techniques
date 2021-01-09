#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
   int errornum;
   char filename[PATH_MAX] = { 0 };
   if (argc != 2)
   {
      fprintf(stderr, "You must supply a filename "
         "as an argument\n");
      return 1;
   }
   strncpy(filename, argv[1], sizeof(filename)-1);
   if ( creat(filename, 00644) == -1 )
   {
      errornum = errno;
      fprintf(stderr, "Can't create file %s\n", 
         filename);
      fprintf(stderr, "%s\n", strerror(errornum));
      return 1;
   }
   return 0;
}
