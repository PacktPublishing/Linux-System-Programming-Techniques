#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DATASIZE 128

int main(void)
{
   char *addr;
   int status;
   pid_t pid;
   const char startmsg[] = "Hello, we are running";
   const char childmsg[] = "Hello from child";
   const char parentmsg[] = "New msg from parent";
   addr = mmap(NULL, DATASIZE, 
      PROT_WRITE | PROT_READ, 
      MAP_SHARED | MAP_ANONYMOUS, -1, 0);
   if (addr == MAP_FAILED)
   {
      perror("mmap");
      return 1;
   }
    
   memcpy(addr, startmsg, strlen(startmsg) + 1);
   printf("Parent PID is %d\n", getpid());
   printf("Original message: %s\n", addr);
   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }
   if (pid == 0)
   {
      /* child */
      memcpy(addr, childmsg, strlen(childmsg) + 1);
   }
   else if(pid > 0)
   {
      /* parent */
      waitpid(pid, &status, 0);
      printf("Child executed with PID %d\n", pid);
      printf("Message from child: %s\n", addr);
      memcpy(addr, parentmsg, 
         strlen(parentmsg) + 1);
      printf("Parent message: %s\n", addr);
   }
   munmap(addr, DATASIZE);
   return 0;
}
