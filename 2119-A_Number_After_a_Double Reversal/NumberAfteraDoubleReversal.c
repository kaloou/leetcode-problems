#include "stdbool.h"
#include "limits.h"
#include "stdio.h"

int reverse(int x);

bool isSameAfterReversals(int num) {
    
    if (num == reverse(reverse(num)))
        return true;
    else
        return false;
}

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

int main() {
    int test_cases[] = {526, 1800, 0};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int num = test_cases[i];
        bool result = isSameAfterReversals(num);
        printf("isSameAfterReversals(%d) = %s\n", num, result ? "true" : "false");
    }

    return 0;
}