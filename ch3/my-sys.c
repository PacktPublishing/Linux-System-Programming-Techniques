#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(void)
{
   char cwd[100] = { 0 }; /* for current dir */
   struct sysinfo si; /* for system information */

   getcwd(cwd, 100); /* get current working dir */
   sysinfo(&si); /* get system information 
                  * (linux only) */
    
   printf("Your user ID is %d\n", getuid());
   printf("Your effective user ID is %d\n", 
      geteuid());
   printf("Your current working directory is %s\n", 
      cwd);
   printf("Your machine has %ld megabytes of " 
      "total RAM\n", si.totalram / 1024  / 1024);
   printf("Your machine has %ld megabytes of "
      "free RAM\n", si.freeram / 1024 / 1024);
   printf("Currently, there are %d processes "
      "running\n", si.procs);
   printf("This process ID is %d\n", getpid());
   printf("The parent process ID is %d\n", 
      getppid());
   return 0;
}
