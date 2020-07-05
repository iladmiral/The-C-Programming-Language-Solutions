#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main(void)
{
    char s[] = "123.45E6";
    printf("%f\n", atof(s));
    return 0;
}

/* atof: convert string to double */
double atof(char s[])
{
    double val, power;
    int i, sign, powSign, powScien;
    for (i = 0; isspace(s[i]); i++); /* skip the white spaces */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') /* handle the scientific notation 123.45e6 */
        i++;
    powSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (powScien = 0; isdigit(s[i]); i++)
        powScien = powScien * 10 + (s[i] - '0');
    
    return (sign * val / power) * pow(10, powSign * powScien);
}