#include<bits/stdc++.h>
// int solve(int arr[],int n,int sum)
// {
//     if(sum==0)
//         return 1;
    
//     if(sum<0)
//         return 0;
    
//     if(n<=0 && sum>=1)
//         return 0;
    
//     return solve(arr,n-1,sum)+solve(arr,n,sum-arr[n-1]);
// }

int solve_dp(int arr[],int n,int sum,vector<vector<long long>>&dp)
{
    if(sum==0)
        return 1;
    
    if(n<=0 || sum<0)
        return 0;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    int left=solve_dp(arr,n-1,sum,dp);
    int right=solve_dp(arr,n,sum-arr[n-1],dp);
    
    return dp[n][sum]=left+right;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
	// return solve(denominations,numDenominations,value);
    vector<vector<long long>>dp(numDenominations+1,vector<long long>(value+1,-1));
    return solve_dp(denominations,numDenominations,value,dp);
}
