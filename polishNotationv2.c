#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* strcmp */
#include <math.h> /* sin, cos, exp & pow */

#define MAXOP 100 /* max size of oprend or oprator */
#define NUMBER '0' /* signal that the number was found */
#define FUNCTION '1' /* signal that a math funtion is found */

int getop(char []);
void push(double);
double pop(void);
void domath(char s[]);

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
            case FUNCTION:
                domath(s);
                break;
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
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
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

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;     /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f into value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return the top value of stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

/* domath: access to various math functions as sin, cos, exp & pow */
void domath(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: unknown funtion\n");
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get the next caracter or numeric oprend */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');   /* wait utile get caracter */
    s[1] = '\0';
    i = 0;
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return FUNCTION;
    }
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