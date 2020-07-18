#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 30

void atoa(int n, char s[]);
void reverse(char s[]);

int main(void) 
{
    int n = -2147483648;
    char s[MAXLINE];
    atoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* atoa : convert integer to an string */
void atoa(int n, char s[])
{
    int sign, i;
    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    
    i = 0;
    do                      /* generate the degit in inverse order */
    {
        s[i++] = n % 10 + '0';  /* get the next degit */
    } 
    while ((n = n / 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse the sting s */
void reverse(char s[])
{
   
}
