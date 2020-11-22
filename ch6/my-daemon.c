#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    pid_t pid;
    FILE *fp;
    time_t now; /* for the current time */
    const char pidfile[] = "/var/run/my-daemon.pid";
    const char daemonfile[] = "/tmp/my-daemon-is-alive.txt";

    if ( (pid = fork()) == -1 )
    {
        perror("Can't fork");
        return 1;
    }
    /* the parent process which will exit */
    else if ( pid > 0 )
    {
        /* open pid-file for writing and error check it */
        if ( (fp = fopen(pidfile, "w")) == NULL )
        {
            perror("Can't open file for writing");
            return 1;
        } 
        fprintf(fp, "%d\n", pid); /* write pid to file */
        fclose(fp); /* close the file pointer */
        exit(0);
    }
    /* the parent process has exited, which makes the rest of
       the code the child process, which is the daemon */
    umask(022); /* reset the umask to something sensible */
    setsid(); /* create a new session for the daemon */
    chdir("/"); /* change working directory to / */
    /* open the "daemonfile" for writing */
    if ( (fp = fopen(daemonfile, "w")) == NULL )
    {
        perror("Can't open daemonfile");
        return 1;
    }
    
    /* here we start the daemons "work" */
    for (;;)
    {
        /* get the current time and write it to the
           "daemonfile" that we opened above */
        time(&now);
        fprintf(fp, "Daemon alive at %s", ctime(&now));
        fflush(fp); /* flush the stream */
        sleep(30);
    }
    return 0;
}
