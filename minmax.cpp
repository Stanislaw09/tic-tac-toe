#include "minmax.h"
#include <QPair>

bool minmax::full(int Board[][3])
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(Board[i][j]==0) return 0;

    return 1;
}

int minmax::Win(int Board[][3])
{
    int sum=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            sum+=Board[i][j];

        if(sum==3)  return 1;
        if(sum==-3) return -1;

        sum=0;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            sum+=Board[j][i];

        if(sum==3)  return 1;
        if(sum==-3) return -1;

        sum=0;
    }

    if(Board[0][0]+Board[1][1]+Board[2][2]==3) return 1;
    if(Board[0][0]+Board[1][1]+Board[2][2]==-3) return -1;
    if(Board[2][0]+Board[1][1]+Board[0][2]==3) return 1;
    if(Board[2][0]+Board[1][1]+Board[0][2]==-3) return -1;

    if(full(Board)==1)
        return 2;
}

int minmax::Move(int nBoard[][3], int z)
{
int board[3][3];
int tab[3][3];

    for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                {
                    board[i][j]=nBoard[i][j];
                    tab[i][j]=1;
                }

    switch(z)
    {
        case -1:
        {
            if(Win(board)==1)   return 10;
            if(Win(board)==2)   return 0;
        }break;

        case 1:
        {
            if(Win(board)==-1)  return -10;
            if(Win(board)==2)   return 0;
        }break;
    }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==0)
                switch(z)
                {
                    case -1:
                    {
                        board[i][j]=-1;
                        tab[i][j]=Move(board, z*(-1));
                        if(tab[i][j]==-10) return -10;
                        board[i][j]=0;
                    }break;

                    case 1:
                    {
                        board[i][j]=1;
                        tab[i][j]=Move(board, z*(-1));
                        if(tab[i][j]==10) return 10;
                        board[i][j]=0;
                    }break;
                }

        switch(z)
        {
            case -1:
            {
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        if(tab[i][j]==0)
                            return 0;

                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        if(tab[i][j]==10)
                            return 10;
            }break;

            case 1:
            {
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        if(tab[i][j]==0)
                            return 0;

                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        if(tab[i][j]==-10)
                            return -10;
            }break;
        }
}

QPair<int,int> minmax::GetMove(int currentBoard[][3])
{
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(currentBoard[i][j]==0)
            {
                currentBoard[i][j]=1;

                if(Move(currentBoard, -1)==10)
                    return qMakePair(i,j);


                else currentBoard[i][j]=0;
            }
        }

        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(currentBoard[i][j]==0)
            {
                currentBoard[i][j]=1;

                if(Move(currentBoard, -1)==0)
                    return qMakePair(i,j);

                currentBoard[i][j]=0;
            }

        }
}
