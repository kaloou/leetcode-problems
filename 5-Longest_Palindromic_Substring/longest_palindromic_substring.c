#include "string.h"
#include "stdbool.h"

char* longestPalindrome(char* s)
{
    int i = 0, j = 0;
    int stringlen = strlen(stringlen);
    char* current_pal = "";

    while(s[i] != '\0')
    {
        while(s[j] != '\0')
        {
            j++;
        }
        i++;
    }
}

bool isPalindrome(char* s)
{
    char* string_reverse;
    int i = strlen(s);

    for (int i = strlen(s);i)
}

#include "stdio.h"

int main(void)
{
    char* string = "babad";
    printf("palindrome = %s", longestPalindrome(string));
    return 0;
}