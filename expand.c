/* 
    * Filename:    expand.c
    * Author:      Khalid BENEDDINE <khaledbeneddine@gmail.com>
    * Date:        29-06-2020
    *
    * The C Programming Language, second edition,
    * by Brian Kernighan and Dennis Ritchie
    *
    * Exercise 3-3, page 63
    Write a function expand(s1,s2) that expands shorthand notations like a-z in
    the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
    and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
    leading or trailing - is taken literally.
*/ 

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0


void expand(char s1[], char s2[]);
int isValidRange(char c1, char c2);

int main(void) 
{
    char s2[1024], s1[1024];
    int c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        s1[i++] = c;
    }
    s1[i] = '\0';
    expand(s1, s2);
    for (int j = 0; s2[j] != '\0'; j++)  
    {
        printf("%c", s2[j]);
    }
    printf("\n");
    return 0;
}

/* expand : expands shorthand notations like a-z in the string s1 into
            the equivalent complete list abc...xyz in s2 */
void expand(char s1[], char s2[])
{
    /* browse s1 char by char */
    int i, j;
    int dash = FALSE;
    for (i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-')
        {
            if (i == 0 || s1[i+1] == '\0')
            {
                /* '-' is leading or trailing, so just copy it. */
               s2[j++] = s1[i]; 
            }
            else
            {
                /* check if is a valid range */
                if (isValidRange(s1[i-1], s1[i+1]))
                {
                    while (s2[j-1] < s1[i+1])
                    {
                        s2[j] = s2[j-1] + 1;
                        j++;
                    }
                    /* skip next character we already printed it. */
                    ++i;
                }
                else
                {
                    s2[j++] = s1[i];
                }
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    /* add the null character at the end of string */
    s2[j] = '\0';
}

/* isValidRange: return non-zero if c1-c2 is valid range */
int isValidRange(char c1, char c2)
{
    if (c1 < c2 && c1 >= 'a' && c2 <= 'z') /* valid range in a-z */
    {
        return 1;
    }
    if (c1 < c2 && c1 >= 'A' && c2 <= 'Z') /* valid range in A-Z */
    {
        return 1;
    }
    if (c1 < c2 && c1 >= '0' && c2 <= '9') /* valid range in 0-9 */
    {
        return 1;
    }
    return 0; /* not a valid range */
}