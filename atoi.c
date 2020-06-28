#include <stdio.h>
#include <ctype.h>

/* covert string to an intger */

int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++); /* skip white-space */
    sign = (s[i] == '-') ? -1 : 1; /* get the sign */
    if (s[i] == '-' || s[i] == '+') /* skip the sign */
    {
        i++;
    }
    for (n = 0; isdigit(s[i]); i++) /* get the degit and convert it */
    {
        n = 10 * n + s[i] - '0';
    }
    return n * sign;
}

int main(void) 
{
    char* s = "-2015";
    printf("%i\n", atoi(s) * 2);
    return 0;
}