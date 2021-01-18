#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DATASIZE 128

int main(void)
{
   int fd;
   float *addr;
   const char memid[] = "/my_memory";
   const float numbers[3] = { 3.14, 2.718, 1.202};
   /* create shared memory file descriptor */
   if ( (fd = shm_open(memid, 
      O_RDWR | O_CREAT, 0600)) == -1)
   {
      perror("Can't open memory fd");
      return 1;
   }

	/* truncate memory to DATASIZE */
	if ( (ftruncate(fd, DATASIZE)) == -1 )
   {
      perror("Can't truncate memory");
      return 1;
   }

   /* map memory using our file descriptor */
   addr = mmap(NULL, DATASIZE, PROT_WRITE, 
      MAP_SHARED, fd, 0);
   if (addr == MAP_FAILED)
   {
      perror("Memory mapping failed");
      return 1;
   }

   /* copy data to memory */
   memcpy(addr, numbers, sizeof(numbers));

   /* wait for enter */
   printf("Hit enter when finished ");
   getchar();
   /* clean up */
   munmap(addr, DATASIZE);
   shm_unlink(memid);
   return 0;
}
