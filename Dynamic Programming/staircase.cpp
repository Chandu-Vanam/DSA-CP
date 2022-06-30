#include<bits/stdc++.h>
using namespace std;
// #define m 1e9+7

// void solve(int n,int &cnt)
// {
//     if(n==0)
//     {
//         cnt++;
//         return;
//     }

//     if(n>=1)
//     solve(n-1,cnt);
    
//      if(n>=2)
//     solve(n-2,cnt);
    
//      if(n>=3)
//     solve(n-3,cnt);
// }

int solve(int n,long long dp[])
{
    const int m=(int)(1e9+7);
    for(int i=n-1;i>=0;i--)
    {
        dp[i]=(dp[i+1]+dp[i+2]+dp[i+3])%m;
    }
    
    return dp[0];
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        long long dp[n+3];
		dp[n]=1;
        dp[n+1]=0;
        dp[n+2]=0;
        
        cout<<solve(n,dp)<<endl;
    }
    return 0;
}
