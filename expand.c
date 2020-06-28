/* 
    author : khaled beneddine

    Write a function expand(s1,s2) that expands shorthand notations like a-z in
    the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
    and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
    leading or trailing - is taken literally.
*/ 

#include <stdio.h>
#include <ctype.h>

/* a-z -> abc...xyz */

void expand(char s1[], char s2[]) 
{
    int i, j, p;
    // loop every character in s1
    for (i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == 'a' && s1[i + 1] == '-'  && s1[i + 2] == 'z')
        {
            for (p = 0; p < 26; p++)
            {
                s2[j++] = p +'a';
            }
            i = i + 2;
        }
        else if (s1[i] == 'a' && s1[i + 1] == '-'  && s1[i + 2] == 'b' && s1[i + 3] == '-'  && s1[i + 4] == 'c')
        {
            for (p = 0; p < 26; p++)
            {
                s2[j++] = p +'a';
            }
            i = i + 4;
        }
        else if (s1[i] == '-' && s1[i + 1] == 'a'  && s1[i + 2] == '-' && s1[i + 3] == 'z')
        {
            for (p = 0; p < 26; p++)
            {
                s2[j++] = p +'a';
            }
            i = i + 3;
        }
        else if (s1[i] == '0' && s1[i + 1] == '-'  && s1[i + 2] == '9')
        {
            for (p = 0; p < 10; p++)
            {
                s2[j++] = p + '0';
            }
            i = i + 2;
        }
        else
        {
            s2[j++] = s1[i];
        }   
    }
    s2[j] = '\0';
}

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