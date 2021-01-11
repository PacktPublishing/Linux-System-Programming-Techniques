#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX 128

int main(void)
{
   int pipefd[2] = { 0 };
   pid_t pid;
   char line[MAX];

   if ( (pipe(pipefd)) == -1 )
   {
      perror("Can't create pipe");
      return 1;
   }
   
   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }

   if (pid > 0)
   {
      /* inside the parent */
      close(pipefd[0]); /* close the read end */
      dprintf(pipefd[1], "Hello from parent");
   }
   else
   {
      /* inside the child */
      close(pipefd[1]); /* close the write end */
      read(pipefd[0], line, MAX-1);
      printf("%s\n", line); /* print message from
                             * the parent */
   }
   return 0;
}
