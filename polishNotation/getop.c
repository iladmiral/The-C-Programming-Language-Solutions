#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get the next caracter or numeric oprend */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');   /* wait utile get caracter */
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if (s[i] == '.') /* collect the fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
