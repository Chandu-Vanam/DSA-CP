#include<bits/stdc++.h>

bool ispossible(int n, int r, int k,long long int c,long long int barrier)
{
    long long int totalmoney=(long long int)r+(long long int)((n-barrier)*k);
    long long int pro=(long long int)(totalmoney/c);
    if(pro<(barrier)){
 
            return false;
        
    }else{
        
        return true;
        
    }
}
int recyclePens(int n, int r, int k, int c ){

	// Write your code here.
    // if(r==0)
    //     return 0;
    
	int res=0,ans;
    int low=0,high=n;
    while(low<=high)
    {
        int x=(low+high)/2;
        if(ispossible(n,r,k,c,x))
        {
            ans=x;
            low=x+1;
        }
        else 
            high=x-1;
    }
    return ans;
}
