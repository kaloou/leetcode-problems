#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/*I know that this code is not optimized at all,
i wrote it this way to practice some concepts*/

bool judgeCircle(char* moves) {
    char const UP = 'U';
    char const DOWN = 'D';
    char const LEFT = 'L';
    char const RIGHT = 'R';


    // get the number of moves
    int i = 0;
    while (moves[i] != '\0')
        i++;
    
    // create an array of moves
    char* array = malloc(sizeof(char) * (i + 1));
    if (array == NULL)
        return false;

    for (; i >= 0; i--)
        array[i] = moves[i];

    // calculate x y 
    int x = 0, y = 0;
    for (i = 0; i <= strlen(moves);i++)
    {
        switch (array[i])
        {
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
        }
    }
    if (x == 0 && y == 0)
        return true;
    else
        return false;
}

int main() {
    char* moves = "UDLR";
    printf("test = %s", judgeCircle(moves) ? "true" : "false");
    return 0;
}