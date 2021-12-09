#include <bits/stdc++.h>
using namespace std;
bool flag=false;
bool isSafe(int board[][10],int n,int i,int j)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    int x=i;
    int y=j;
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNqueen(int board[][10],int n,int i)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q\t";
                }else
                {
                    cout<<"-\t";
                }
            }
            cout<<endl;
            flag=true;
        }

        cout<<endl;
        return false;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,n,i,j))
        {
            board[i][j]=1;

            bool isItOk=solveNqueen(board,n,i+1);
            if(isItOk)
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}
int main() {
    int n;
    while(cin>>n){
        int board[10][10]={0};
        solveNqueen(board,n,0);
        if(!flag)
        {
            cout<<"Not Possible"<<endl;
        }

    }
}