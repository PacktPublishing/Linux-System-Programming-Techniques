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
   float numbers[3];

   /* open memory file descriptor */
   fd = shm_open(memid, O_RDONLY, 0600);
   if (fd == -1)
   {
      perror("Can't open file descriptor");
      return 1;
   }

   /* map shared memory */
   addr = mmap(NULL, DATASIZE, PROT_READ, 
      MAP_SHARED, fd, 0);
   if (addr == MAP_FAILED)
   {
      perror("Memory mapping failed");
      return 1;
   }

   /* read the memory and print the numbers */
   memcpy(numbers, addr, sizeof(numbers));
   for (int i = 0; i<3; i++)
   {
      printf("Number %d: %.3f\n", i, numbers[i]);
   }

   return 0;
}
