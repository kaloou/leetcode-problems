#include "stdio.h"

char* isPalindrome(int x) {
    
    int original = x;
    long long reverse = 0;
    int chiffre;
    
    if (x < 0)
        
    while (x > 0 )
    {
        chiffre = x % 10;
        reverse = reverse * 10 + chiffre;
        x = x / 10;
    }

    if (original == reverse)
        return "true";
    else 
        return "false";
}

int main (void)
{
    printf("output : %s", isPalindrome(1234567899
));
    return 0;
}