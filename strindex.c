#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line */

int getline(char s[], int max);
int strindex(char s[], char t[]);

char pattren[] = "ould"; /* pattren to search for */

/* find all line matching with pattren */
int main(void) 
{
    char line[MAXLINE];
    int found = 0;
    while (getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattren) >= 0)
        {
            printf("%s\n", line);
            found++;
        }
    }
    return found;
}

/* getline: get line into s, return the length */
int getline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim >= 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\n' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}