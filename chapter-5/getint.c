#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 100

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(void)
{
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
    return 0;
}

/* getint: get the next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white spaces */
    ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    //printf("%i\n", sign);
    if (c == '-' || c == '+')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
        
    *pn = *pn * sign;
    //printf("%i\n", *pn);
    if (c != EOF)
        ungetch(c);
    return c;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() /* get a (possibly pushed-back) character  */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("erorr: too many character\n");
    else
        buf[bufp++] = c;
}