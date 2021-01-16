#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAXSIZE 4096

int main(int argc, char *argv[])
{
   int fd; /* for the file descriptor */
   int maxread; /* the maximum we want to read*/
   off_t filesize; /* for the file size */
   struct stat fileinfo; /* struct for fstat */
   char rbuf[MAXSIZE] = { 0 }; /* the read buffer */

   if (argc < 3 || argc > 4)
   {
      fprintf(stderr, "Usage: %s [path] [from pos] "
         "[bytes to read]\n", argv[0]);
      return 1;
   }

   /* open the file in read-only mode and get
      the file size */
   if ( (fd = open(argv[1], O_RDONLY)) == -1 )
   {
      perror("Can't open file for reading");
      return 1;
   }
   fstat(fd, &fileinfo);
   filesize = fileinfo.st_size;

   /* determine the max size we want to read
      so we don't overflow the read buffer */
   if ( filesize >= MAXSIZE )
   {
      maxread = MAXSIZE-1;
   }
   else if ( argv[3] != NULL )
   {
      if ( atoi(argv[3]) >= MAXSIZE )
      {
         fprintf(stderr, "To big size specified\n");
         return 1;
      }
      maxread = atoi(argv[3]);
   }
   else
   {
      maxread = filesize;
   }
    
   /* move the read position */
   lseek(fd, atoi(argv[2]), SEEK_SET);
   /* read the content and print it */
   if ( (read(fd, rbuf, maxread)) == -1 )
   {
      perror("Can't read file");
      return 1;
   }
   printf("%s\n", rbuf);
   return 0;
}
