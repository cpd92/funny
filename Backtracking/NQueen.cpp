#include<bits/stdc++.h>

const int N=8;
std::vector<std::vector<std::vector<char>>> result;

bool isValid(std::vector<std::vector<char>>&,int,int);

void NQueen(std::vector<std::vector<char>>& board,int row)
{
    if(row>N-1)
    {
        result.push_back(board);
        return ;
    }

    for(int j=0;j<N;++j)
    {
        board[row][j]='Q';
        if(isValid(board,row,j))
        {
            NQueen(board,row+1);
        }
        board[row][j]='.';
    }
}

bool isValid(std::vector<std::vector<char>>& board,int i,int j)
{
    for(int k=0;k<N;++k)
    {
        if(board[i][k]=='Q' && k!=j)
        {
            return false;
        }
    }
    for(int k=0;k<N;++k)
    {
        if(board[k][j]=='Q' && k!=i)
        {
            return false;
        }
    }

    for(int x=0,y=N-1;x<N,y>=0;x++,y--)
    {
        if(board[x][y]=='Q' && x!=i && y!=j)
        {
            return false;
        }
    }
    for(int x=N-1,y=0;x>=0,y<N;x--,y++)
    {
        if(board[x][y]=='Q' && x!=i && y!=j)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    std::vector<std::vector<char>> board;
    for(int i=0;i<N;++i)
    {
        std::vector<char> temp;
        for(int j=0;j<N;++j)
        {
            temp.push_back('.');
        }
        board.push_back(temp);
    }

    NQueen(board,0);

    int i=0;
    for(const auto& itr:result)
    {
        const std::vector<std::vector<char>>& board=itr;
        std::cout<<"Solution "<<++i<<":"<<std::endl;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                std::cout<<board[i][j];
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    return 0;
}
