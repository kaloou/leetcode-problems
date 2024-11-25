#include "string.h"

int furthestDistanceFromOrigin(char* moves)
{
    int left_counter = 0, right_counter = 0, tiret_counter = 0;

    for(int i = 0; i <= strlen(moves);i++)
    {
        switch (moves[i])
        {
            case 'L':
                left_counter++;
                break;
            case 'R':
                right_counter++;
                break;
            case '_':
                tiret_counter++;
                break;
        }
    }
    if (right_counter > left_counter)
        return right_counter - left_counter + tiret_counter;
    else
        return left_counter - right_counter + tiret_counter;
}