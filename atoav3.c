#include <stdio.h>
#include <ctype.h>
#include <string.h>

void atoa(int n, char s[]);
void reverse(char s[]);

int main(void) 
{
    int n = -123;
    int size = sizeof(n) / sizeof(int);
    char s[size];
    atoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* atoa : convert integer to an string, use a recursive function */
void atoa(int n, char s[])
{
    
    strcpy(s, printd(n));
    s[strlen(s)] = '\0';
}
