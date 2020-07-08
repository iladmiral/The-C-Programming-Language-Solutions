#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of oprend or oprator */
#define NUMBER '0' /* signal that the number was found */

int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void swap(void);
void duplicate(void);

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
                duplicate();
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                swap();
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
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

/* showTop: print the element in the top of stack */
void showTop(void)
{
    if (sp > 0)
        printf("%lf\n", val[sp-1]);
    else
        printf("error: the stack is empty\n");
}

/* swap: swap the top two elements */
void swap(void)
{
    if (sp > 0)
    {
        double temp1 = pop();
        double temp2 = pop();
        push(temp1);
        push(temp2);
    }
    else
    {
        printf("error: stack is empty, nothing to swap\n");
    }
}
/* duplicate: to duplicate the top element of the stack */
void duplicate(void)
{
    push(val[sp-1]);
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