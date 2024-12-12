#include <stdio.h>
int isValidSudoku(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        int rows[10] = {0};
        for (int j = 0; j < 9; j++)
        {
            int temp = board[i][j];
            if (board[i][j] != 0 && rows[temp] == 1)
            {
                return 0;
            }
            rows[temp] = 1;
        }
    }
    for (int j = 0; j < 0; j++)
    {
        int cols[10] = {0};
        for (int i = 0; i < 9; i++)
        {
            int temp = board[i][j];
            if (board[i][j] != 0 && cols[temp] == 1)
            {
                return 0;
            }
            cols[temp] = 1;
        }
    }
    for (int block = 0; block < 9; block++)
    {
        int subgrid[10] = {0};
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++)
        {
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++)
            {
                int temp = board[i][j];
                if (board[i][j] != 0 && subgrid[temp] == 1)
                {
                    return 0;
                }
                subgrid[temp] = 1;
            }
        }
    }
    return 1;
}

int main()
{
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if (isValidSudoku(sudoku))
    {
        printf("Valid Sudoku\n");
    }
    else
    {
        printf("Invalid Sudoku\n");
    }
    return 0;
}