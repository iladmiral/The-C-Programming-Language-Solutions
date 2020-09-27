#include <stdio.h>

/* strcat pointer version
   strcat(s, t) copies the t string at the end of s */
char *strcat(char *s, char *t)
{
    while (*s) /* find end of s */
        s++;
    
    while (*t) /* copy the t content on s */
        *s++ = *t++;
    
    *s = '\0';
    return s;
}

int main(void)
{
    char s[] = "Hi there!";
    char t[] = "What's up";
    
    strcat(s, t);

    printf("%s\n", s);
    return 0;
}