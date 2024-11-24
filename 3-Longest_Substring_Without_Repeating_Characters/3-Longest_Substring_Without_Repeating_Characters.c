#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int i = 0, j = 0, max_len = 0, current_len = 0;

    while (s[i] != '\0')
    {
        char sub_string[256] = {0};
        current_len = 0;
        j = i;
        while (s[j] != '\0')
        {
            // verif si char already in
            if (sub_string[(unsigned char)s[j]] == 1)
                break;

            // mark it as seen
            sub_string[(unsigned char)s[j]] = 1;
            current_len++;
            j++;
        }

        if (current_len > max_len)
            max_len = current_len;
        i++;
    }

    return max_len;
}

int main() {
    char str[] = "abcabcbb";
    printf("La longueur de la plus longue sous-chaîne sans répétition est : %d\n", lengthOfLongestSubstring(str));
    return 0;
}
