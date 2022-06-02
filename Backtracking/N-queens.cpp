#include<bits/stdc++.h>
vector<vector<int>>result;

bool ispossible(vector<vector<int>>&ans,int row,int col,int n)
{
    int tmp_row=row;
    int tmp_col=col;
    
    while(row>=0 && col>=0)
    {
        if(ans[row][col]==1)
            return false;
        
        row--;
        col--;
    }
    
    row=tmp_row;
    col=tmp_col;
    
   	while(col>=0)
    {
		if(ans[row][col]==1)
            return false;
        col--;
    }
    
     row=tmp_row;
    col=tmp_col;
    
    while(row<n && col>=0)
    {
     	if(ans[row][col]==1)
            return false;
        
        row++;
        col--;   
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,int n)
{
    if(col==n)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v.push_back(board[i][j]);
            }
        }
        // cout<<endl;
        result.push_back(v);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(ispossible(board,row,col,n))
        {
            board[row][col]=1;
            solve(col+1,board,n);
    
            board[row][col]=0;
        }
    }   
}
                               
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
 
    vector<vector<int>>board(n,vector<int>(n,0));
   solve(0,board,n);
    return result;
}
