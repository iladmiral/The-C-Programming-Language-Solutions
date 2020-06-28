/*
    author : Khalid BENEDDINE

    3-2 : Write a function escape(s,t) that converts characters like newline and tab into
    visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
    function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>
#define TRUE  1
#define FALSE 0

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) /* count degit, white, other */ 
{
    char s[1024], t[1024];
    int c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        t[i++] = c;
    }
    t[i] = '\0';
    unescape(s, t);
    for (int j = 0; s[j] != '\0'; j++)  
    {
        printf("%c", s[j]);
    }
    printf("\n");
    return 0;
}

// convert characters like newline and tab on t[] into visible escape sequences like \n, \t on s[]
void escape(char s[], char t[])
{
    int i = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
            case '\n':
                s[i] = '\\';
                s[++i] = 'n';
                break;
            case '\t':
                s[i] = '\\';
                s[++i] = 't';
                break;
            default:
                s[i] = t[i];
                break;
        }
        i++;
    }
    s[i] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    int slash = FALSE;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
            case '\\':
                slash = TRUE;
                break;
            case 'n':
                if (slash)
                {
                    s[j++] = '\n';
                    slash = FALSE;
                    break;
                }
            case 't':
                if (slash)
                {
                    s[j++] = '\t';
                    slash = FALSE;
                    break;
                }
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}