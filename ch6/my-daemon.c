#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

int main(void)
{
   pid_t pid;
   FILE *fp;
   time_t now; /* for the current time */
   const char pidfile[] = "/var/run/my-daemon.pid";
   const char daemonfile[] = 
      "/tmp/my-daemon-is-alive.txt";

   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }
   else if ( (pid != 0) )
   {
      exit(0);
   }
   /* the parent process has exited, so this is the
    * child. create a new session to lose the 
    * controlling terminal */
   setsid();
    
   /* fork again, creating a grandchild, 
    * the actual daemon */
   if ( (pid = fork()) == -1 )
   {
      perror("Can't fork");
      return 1;
   }
   /* the child process which will exit */
   else if ( pid > 0 )
   {
      /* open pid-file for writing and error 
       * check it */
      if ( (fp = fopen(pidfile, "w")) == NULL )
      {
         perror("Can't open file for writing");
         return 1;
      }
      /* write pid to file */
      fprintf(fp, "%d\n", pid); 
      fclose(fp); /* close the file pointer */
      exit(0);
   }

   umask(022); /* set the umask to something ok */
   chdir("/"); /* change working directory to / */
   /* open the "daemonfile" for writing */
   if ( (fp = fopen(daemonfile, "w")) == NULL )
   {
      perror("Can't open daemonfile");
      return 1;
   }
   /* from here, we don't need stdin, stdout or, 
    * stderr anymore, so let's close them all, 
    * then re-open them to /dev/null */
   close(STDIN_FILENO);
   close(STDOUT_FILENO);
   close(STDERR_FILENO);
   open("/dev/null", O_RDONLY); /* 0 = stdin */
   open("/dev/null", O_WRONLY); /* 1 = stdout */
   open("/dev/null", O_RDWR); /* 2 = stderr */

   /* here we start the daemons "work" */
   for (;;)
   {
      /* get the current time and write it to the
         "daemonfile" that we opened above */
      time(&now);
      fprintf(fp, "Daemon alive at %s", 
         ctime(&now));
      fflush(fp); /* flush the stream */
      sleep(30);
   }
   return 0;
}
