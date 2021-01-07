#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    if ( (isatty(STDOUT_FILENO) == 1) )
    {
        printf("It's a TTY with the name %s\n",
            ttyname(STDOUT_FILENO));
    }
    else
    {
        perror("isatty");
    }
    printf("Hello world\n");
    return 0;
}
