#include <stdio.h>
#include <string.h>
#include <ctype.h>

void atob(int n, char s[], int b);
void reverse(char s[]);

int main(void) 
{
    int n = -2000;
    int b = 50; /* the base of conversion */
    int size = sizeof(n) / sizeof(int);
    char s[size];
    atob(n, s, b);
    printf("%s\n", s);
    return 0;
}

/* atob : convert integer to hex than save it in string */
void atob(int n, char s[], int b)
{
    int sign, i;
    i = 0;
    sign = n;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /* handle the errors no base < 2, no base > symbols length */
    if (b < 2 || b > strlen(symbols))
        return;
    if (n < 0)
        n = -n;
    /* convert to hex */
    do               /* generate symbols in reverse order */
    {
        s[i++] = symbols[(n % b)]; /* add the next degit */
    }
    while (n /= b); /* delete it */

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
