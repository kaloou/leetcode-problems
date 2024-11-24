#include "limits.h"

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int number = 0;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-'){
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
        i++;

    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        if (number > INT_MAX / 10 || (number == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        number = number * 10 + digit;
        i++;
    }
    return number * sign;
}

#include "stdio.h"
int main(void)
{
    printf("res = %d",myAtoi("91283472332"));
    return 0;
}