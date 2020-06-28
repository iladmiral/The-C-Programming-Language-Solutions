#include <stdio.h>

int main(void) /* count degit, white, other */ 
{
    int nwhite, nother, c; int ndegit[10] = {0};
    nwhite = nother = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c) 
        {
            case '0' : case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndegit[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("Degit = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", ndegit[i]);
    }
    printf("\nwhite = %i \nother = %i\n", nwhite, nother);
    return 0;
}