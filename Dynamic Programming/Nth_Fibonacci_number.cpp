#include<bits/stdc++.h>
using namespace std;

int solve(int n,int dp[])
{
    if(n<=1)
        return n;
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=solve(n-1,dp)+solve(n-2,dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[n+1]={-1};
    
    for(int i=0;i<=n;i++)
        dp[i]=-1;
        // cout<<dp[i];
    
    cout<<solve(n,dp);
    return 0;
}
