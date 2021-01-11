#include <stdio.h>

int main(void)
{
    FILE *fp;
    signed char c;
    const char fifoname[] = "/tmp/my-2nd-fifo";
    if ( (fp = fopen(fifoname, "r")) == NULL )
    {
        perror("Can't open FIFO");
        return 1;
    }
    while ( (c = getc(fp)) != EOF )
        putchar(c);
    fclose(fp);
    return 0;
}
