#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"

int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
    
bool isAnagram(char* s, char* t) {
    
    bool result;
    char* s_copy;
    char *t_copy;
    result = false;
    
    if (strlen(s) != strlen(t))
        result = false;
    
    s_copy = strdup(s);
    t_copy = strdup(t);
    
    
    
    qsort(s_copy, strlen(s), sizeof(char), compare);
    qsort(t_copy, strlen(t), sizeof(char), compare);
    
    
    
    if (strcmp(s_copy, t_copy) == 0)
        result = true;
    
    free(s_copy);
    free(t_copy);
        
    return result;
}

int main(void)
{
    printf("%d\n",isAnagram("anagram","naagram"));
}

