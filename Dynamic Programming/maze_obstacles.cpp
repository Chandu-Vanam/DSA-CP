#include<bits/stdc++.h>
const int mod = (int)1e9+7;

int solve(int n,int m,vector<vector<int>>&grid,int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1)
        return 0;
    
    if(i==n-1 && j==m-1)
        return 1;
    
    return solve(n,m,grid,i+1,j)+solve(n,m,grid,i,j+1);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    // return solve(n,m,mat,0,0);
    
    long long dp[n][m];
    dp[n-1][m-1]=1;
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
                continue;
            
            if(mat[i][j]==-1)
            {
                dp[i][j]=0;
                continue;
            }
            
            dp[i][j]=0;
            
            if(j<m-1) dp[i][j]+=dp[i][j+1];
            if(i<n-1) dp[i][j]+=dp[i+1][j];
            
            dp[i][j]%=mod;
        }
    }
    
    return dp[0][0];
}
