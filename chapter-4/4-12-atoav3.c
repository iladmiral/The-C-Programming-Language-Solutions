#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 30

void atoa(int n, char s[]);
void reverse(char s[]);

int main(void) 
{
    int n = -155216259;
    char s[MAXLINE];
    atoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* atoa : convert integer to an string, use a recursive function */
void atoa(int n, char s[])
{
    static int i;
    int number = n;
    if (n < 0)    /* record sign */
    {
        s[0] = '-';
        n = -n;             /* make n positive */
    }
    i = 1;
    if (n / 10)
    {
        atoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    if (n == -number)
    {
        s[i] = '\0';
    }
}
