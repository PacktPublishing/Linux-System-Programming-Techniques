#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>

void sigHandler(int sig);

/* moved these variables to the global scope
   since they need to be access/deleted/closed
   from the signal handler */
FILE *fp;
const char pidfile[] = "/var/run/my-daemon.pid";

int main(void)
{
    pid_t pid;
    time_t now; /* for the current time */
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
    /* from here, we don't need stdin, stdout or, stderr
       anymore, so let's close them all */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    /* register the signal handler for TERM, INT, QUIT, 
       and ABRT */
    signal(SIGTERM, sigHandler);
    signal(SIGINT, sigHandler);
    signal(SIGQUIT, sigHandler);
    signal(SIGABRT, sigHandler);
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

void sigHandler(int sig)
{
    int status = 0;
    if ( sig == SIGTERM || sig == SIGINT 
        || sig == SIGQUIT 
        || sig == SIGABRT )
    {
        /* remove the pid-file */
        if ( (unlink(pidfile)) == -1 )
            status = 1;
        if ( (fclose(fp)) == EOF )
            status = 1;
        exit(status); /* exit with the status set */
    }
    else /* some other signal */
    {
        exit(1);
    }
}
