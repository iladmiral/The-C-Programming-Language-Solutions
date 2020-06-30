#include <stdio.h>
#include <ctype.h>
#include <string.h>

void atoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) 
{
    int n = -20;
    int width = 10;
    int size = sizeof(n) / sizeof(int);
    char s[size];
    atoa(n, s, width);
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
        s[i++] = num % 10 + '0';  /* get the next degit */
    } 
    while ((num = num / 10)); /* delete it and wait until the length of s = width*/
    if (sign < 0)
        s[i++] = '-';
    while (i < w) /* add blank spaces to reach the condition */ 
        s[i++] = ' ';
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
