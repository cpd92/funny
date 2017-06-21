#include <iostream>
#include <bits/stdc++.h>

/*A algorithm to solve a 9×9 sudoku problem */


const int N=9;
const int UNDEFINED=0;

bool FindNotDefined(int board[N][N],int& oi,int& oj)
{
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(board[i][j]==UNDEFINED)
            {
                oi=i;oj=j;
                return true;
            }
        }
    }

    return false;
}

bool UseInBox(int board[N][N],int box_start_row,int box_start_col,int num)  //box check
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(board[row+box_start_row][col+box_start_col]==num)
                return true;
        }
    }
    return false;
}

bool UseInCol(int board[N][N],int col,int num)
{
    for(int row=0;row<N;++row)
    {
        if(board[row][col]==num)
        {
            return true;
        }
    }

    return false;
}

bool UseInRow(int board[N][N],int row,int num)
{
    for(int col=0;col<N;++col)
    {
        if(board[row][col]==num)
        {
            return true;
        }
    }

    return false;
}

bool isValidPosition(int board[N][N],int row,int col,int num)
{
    return UseInRow(board,row,num)==false && UseInCol(board,col,num)==false \
            && UseInBox(board,row-row%3,col-col%3,num)==false ;
}

bool sudoku(int board[N][N])
{
    int row,col;

    if(FindNotDefined(board,row,col)==false)
        return true;  // has resolve all

    for(int num=1;num<=N;++num) //attempt to find a valid position
    {
        if(isValidPosition(board,row,col,num))
        {
            board[row][col]=num;

            if(sudoku(board))
            {
                return true;
            }
            
            board[row][col]=UNDEFINED;        //backtracking
        }
    }

    return false;
}

int main()
{
   clock_t c_start = clock();
    int board[N][N] = {{3, 1, 0, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 0, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 0, 0, 0}};

    if (sudoku(board))
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists");
    }

    printf("Time taken: %.3fs\n", (double)(clock() - c_start)/CLOCKS_PER_SEC);

    return 0;
}
