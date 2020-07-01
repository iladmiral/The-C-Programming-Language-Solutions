#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int rightmost(char s[], char t[]);

char pattren[] = "ould"; /* pattren to search for */

/* find all lines maching with pattren, then print the rightmost occurence of t in s */
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    while (getline(line, MAXLINE) > 0)
    {
        if (rightmost(line, pattren) >= 0)
        {
            printf("%s\nrightmost index : %i\n", line, rightmost(line, pattren));
        }
    }
    return 0;
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

/* rightmost: return the rightmost occurence index of t in s, -1 if none */
int rightmost(char s[], char t[])
{
    int i, j, k;
    int index = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\n' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
        {
            index = i;
            continue;
        }
    }
    return index;
}