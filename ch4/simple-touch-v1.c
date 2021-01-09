#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <linux/limits.h>

int main(int argc, char *argv[])
{
   char filename[PATH_MAX] = { 0 };
   if (argc != 2)
   {
      fprintf(stderr, "You must supply a filename "
          "as an argument\n");
      return 1;
   }
   strncpy(filename, argv[1], PATH_MAX-1);
   creat(filename, 00644);
   return 0;
}
