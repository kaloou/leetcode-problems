#include "limits.h"
#include "stdio.h"

int reverse(int x)
{
    int digit;
    int reverse_x = 0;
    while(x != 0)
    {
        digit = x % 10;

        if (reverse_x > INT_MAX / 10 || 
            (reverse_x == INT_MAX / 10 && digit > INT_MAX % 10) ||
            reverse_x < INT_MIN / 10 ||
            (reverse_x == INT_MIN / 10 && digit < INT_MIN % 10))
            return 0;

        reverse_x = reverse_x * 10 + digit;
        x = x / 10;
    }
    return reverse_x;
    
}

int main(void)
{
    int x = 120;
    printf("reverse de 120 = %d",reverse(x));
    return 0;
}