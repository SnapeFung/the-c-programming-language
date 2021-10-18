#include <stdio.h>

int main()
{
    printf("%x\n", (unsigned)(~0) >> 3);
    printf("%x\n", (~0) << 3);
    return 0;
}