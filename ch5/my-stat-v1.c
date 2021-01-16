#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
   struct stat filestat;
   if ( argc != 2 )
   {
      fprintf(stderr, "Usage: %s <file>\n", 
         argv[0]);
      return 1;
   }
   if ( stat(argv[1], &filestat) == -1 )
   {
      fprintf(stderr, "Can't read file %s: %s\n", 
         argv[1], strerror(errno));
      return errno;
   }
   printf("Inode: %lu\n", filestat.st_ino);
   printf("Size: %zd\n", filestat.st_size);
   printf("Links: %lu\n", filestat.st_nlink);
   return 0;
}
