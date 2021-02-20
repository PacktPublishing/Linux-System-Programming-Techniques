#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
   pid_t pid;
   printf("My PID is %d\n", getpid());
   /* fork, save the PID, and check for errors */
   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }
   if (pid == 0)
   {
      /* if pid is 0 we are in the child process */
      printf("Hello from the child process!\n");
      for(int i = 0; i<10; i++)
      {
          printf("Counter in child: %d\n", i);
      }
   }
   else if(pid > 0)
   {
      /* parent process */
      printf("My child has PID %d\n", pid);
      wait(&pid);
   }
   return 0;
}
