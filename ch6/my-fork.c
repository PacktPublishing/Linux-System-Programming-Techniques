#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
   pid_t pid;
   int status;

   /* Get and print my own pid, then fork
      and check for errors */
   printf("My PID is %d\n", getpid());
   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }
   if (pid == 0)
   {
      /* If pid is 0 we are in the child process,
         from here we execute 'man ls' */
      if ( execl("/usr/bin/man", "man", "ls", 
         (char*)NULL) == -1 )
      {
         perror("Can't exec");
         return 1;
      }
   }
   else if(pid > 0)
   {
      /* In the parent we must wait for the child
         to exit with waitpid(). Afterward, the
         child exit status is written to 'status' */
      waitpid(pid, &status, 0);
      printf("Child executed with PID %d\n", pid);
      printf("Its return status was %d\n", status);
   }
   else
   {
      fprintf(stderr, "Something went wrong "
         "forking\n");
      return 1;
   }
   return 0;
}
