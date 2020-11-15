#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void sigHandler(int sig);

int main(void)
{
    pid_t pid; /* to store our pid in */
    pid = getpid(); /* get the pid */
    printf("Program running with PID %d\n", pid);
    /* register two signal handlers, one for USR1
       and one for USR2 */
    signal(SIGUSR1, sigHandler);
    signal(SIGUSR2, sigHandler);
    /* infinite loop to keep the program running */
    for (;;)
    {
        sleep(10);
    }
    return 0;
}
/* the signal handling function */
void sigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Received USR1 signal\n");
    }
    else if (sig == SIGUSR2)
    {
        printf("Received USR2 signal\n");
    }
    /* when the signal has been triggered, we
       must re-register it */
    signal(sig, sigHandler);
}
