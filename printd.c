#include <stdio.h>

/* printd: print an integer as string */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

int main(void)
{
    printd(123);
    return 0;
}