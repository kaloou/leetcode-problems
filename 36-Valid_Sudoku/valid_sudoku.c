#include "stdbool.h"
#include "stdio.h"

void reset_freq(int* frequence)
{
    for (int y = 0; y < 10; y++)
        frequence[y] = 0;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    bool result = true;
    int frequence[10];
    
    for (int i = 0; i <= 6; i += 3) // ligne de box
    {
        for (int x = i; x < i + 3; x++) // check ligne
        {
            reset_freq(frequence);
            for (int x2 = 0; x2 < boardColSize[x]; x2++)
            {
                if (board[x][x2] >= '1' && board[x][x2] <= '9')
                {
                    int num = board[x][x2] - '0';
                    frequence[num]++;
                    if (frequence[num] > 1)
                        return false;
                }
            }
        }
        
        for (int j = 0; j <= 6; j += 3) // colonne de box
        {
            for (int y = j; y < j + 3; y++) // check colonne
            {
                reset_freq(frequence);
                for (int y2 = 0; y2 < boardSize; y2++)
                {
                    if (board[y2][y] >= '1' && board[y2][y] <= '9')
                    {
                        int num = board[y2][y] - '0';
                        frequence[num]++;
                        if (frequence[num] > 1)
                            return false;
                    }
                }
            }
            
            reset_freq(frequence);
            for (int k = 0; k < 3; k++) // check the box
            {
                for (int l = 0; l < 3; l++)
                {
                    if (board[i + k][j + l] >= '1' && board[i + k][j + l] <= '9')
                    {
                        int num = board[i + k][j + l] - '0';
                        frequence[num]++;
                        if (frequence[num] > 1)
                            return false;
                    }
                }
            }
        }
    }
    return result;
}

int main(void)
{
    int board_size = 9;
    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9}; // taille des colonnes
    char* input[9] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
        };

    printf("%d\n", isValidSudoku(input, board_size,boardColSize));
    return 0;
}
