#include <stdio.h>
#include <ctype.h>
#include <string.h>

void atoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) 
{
    int n = 20;
    int size = sizeof(n) / sizeof(int);
    char s[size];
    atoa(n, s, 10);
    printf("%s\n", s);
    return 0;
}

/* atoa : convert integer to an string with a minimum with w */
void atoa(int n, char s[], int w)
{
    int sign, i;
    unsigned int num;
    if ((sign = n) < 0)     /* record sign */
        num = -n;           /* make n positive */
    else                    
        num = n;
    
    i = 0;
    do                      /* generate the degit in inverse order */
    {   
        if (num > 0)
        {
            s[i++] = num % 10 + '0';  /* get the next degit */
        }
        else        /* add blank spaces to reach the condition */
        {
            s[i++] = ' ';
        }
    } 
    while ((num = num / 10) > 0 || i < w); /* delete it and wait until the length of s = width*/
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
    for (i = 0, j = strlen(s) - 1; i <= j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
