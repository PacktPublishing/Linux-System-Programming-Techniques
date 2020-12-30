#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig);

int main(void)
{
    pid_t pid; /* to store our pid in */
    pid = getpid(); /* get the pid */
    struct sigaction action; /* for sigaction */
    sigset_t set; /* signals we want to ignore */
    printf("Program running with PID %d\n", pid);
    /* prepare sigaction() */
    action.sa_handler = sigHandler;
    sigfillset(&action.sa_mask);
    action.sa_flags = SA_RESTART;
    /* register two signal handlers, one for USR1
       and one for USR2 */
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
 
    /* create a "signal set" for sigprocmask() */
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    /* block SIGINT and run an infinite loop */
    sigprocmask(SIG_BLOCK, &set, NULL);
    /* infinite loop to keep the program running */
    for (;;)
    {
        sleep(10);
    }
    sigprocmask(SIG_UNBLOCK, &set, NULL);
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
}
