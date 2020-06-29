#include <stdio.h>
#include <ctype.h>
#include <string.h>

void atoa(int n, char s[]);
void reverse(char s[]);

int main(void) 
{
    int n = -2147483648;
    int size = sizeof(n) / sizeof(int);
    char s[size];
    atoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* atoa : covert integer to an string */
void atoa(int n, char s[])
{
    int sign, i;
    unsigned int num;
    if ((sign = n) < 0)     /* record sign */
        num = -n;             /* make n positive */
    
    i = 0;
    do                      /* generate the degit in inverse order */
    {
        s[i++] = num % 10 + '0';  /* get the next degit */
    } 
    while ((num = num / 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse the sting s */
void reverse(char s[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i != j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
