#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of oprend or oprator */
#define NUMBER '0' /* signal that the number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get the next caracter or numeric oprend */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || s[0] == '\t');   /* wait utile get caracter */
    s[1] = '\0';
    if (!isdigit(c) || c != '.')
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

#define BUFSIZE 100

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