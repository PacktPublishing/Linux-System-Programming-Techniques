#include <unistd.h>

int main(void)
{
    write(1, "hello, world\n", 13);
    return 0;
}