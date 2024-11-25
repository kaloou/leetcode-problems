#include <stdbool.h>

bool areNumbersAscending(char* s)
{
    int i = 0;
    int previous_number = 0;

    while (s[i] != '\0')
    {
        if (s[i] < '0' || s[i] > '9')
        {
            i++;
            continue;
        }
        
        int number = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            number = number * 10 + (s[i] - '0');
            i++;
        }

        if (number <= previous_number) {
            return false;
        }
        previous_number = number;
    }

    return true;
}

#include <stdio.h>

int main()
{
    char s[] = "1 box has 3 blue 10 red 20 green and 30 yellow marbles";

    if (areNumbersAscending(s))
        printf("Les nombres sont en ordre croissant.\n");
    else
        printf("Les nombres ne sont pas en ordre croissant.\n");
    return 0;
}
