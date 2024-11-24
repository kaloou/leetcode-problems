#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j;

    // Cas de base : tableau vide
    if (strsSize == 0) {
        return "";
    }

    // len de l'élément le plus petit
    int min_len = strlen(strs[0]);
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < min_len) {
            min_len = len;
        }
    }

    // alloc
    char* prefix = (char*)malloc(sizeof(char) * (min_len + 1));
    if (!prefix) {
        return NULL;
    }

    for (i = 0; i < min_len; i++) {
        char current_char = strs[0][i];

        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != current_char) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = current_char;
    }
    prefix[i] = '\0';
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Le plus long préfixe commun est : \"%s\"", result);
    
    free(result);
    return 0;
}