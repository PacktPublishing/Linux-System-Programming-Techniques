#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void sigHandler(int sig);

int main(void)
{
    time_t now; /* for the current time */
    /* register the signal handler */
    signal(SIGUSR1, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGHUP, sigHandler);

    for (;;) /* main loop */
    {
        time(&now); /* get current date & time */
        printf("Daemon alive at %s", ctime(&now));
        fflush(stdout);
        sleep(30);
    }
    return 0;
}

void sigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Hello world!\n");
    }
    else if (sig == SIGTERM)
    {
        printf("Doing some cleanup...\n");
        printf("Bye bye...\n");
        exit(0);
    }
    else if (sig == SIGHUP)
    {
        printf("HUP is used to reload any " 
            "configuration files\n");
    }
    /* re-register the signal that was triggered */
    signal(sig, sigHandler);
}
