bool isValid(char* s) {
    const int open = 1
    const int closed = 0

    int first, second, third = 2;
    int  i = 0;


    while (s[i] != '\0'){

        if(s[i] == '('){
            first = open;
            while (s[i] != ')'){
                i++;
            }
            if (second != open && third != open)
                first = closed;
        }

        else if(s[i] == '{'){
            second = open;
            while (s[i] != '}'){
                i++
            }
            if (first != open && third != open)
                second = closed;
        }

        else if(s[i] == '['){
            third = open;
            while (s[i] != ']'){
                i++
            }
            if (second != open && first != open)
                third = closed;
        }

        i++;
    }
}

#include "stdio.h"
int main(void){

}