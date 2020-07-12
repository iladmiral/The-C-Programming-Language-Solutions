#include <stdio.h>
#include "calc.h"
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