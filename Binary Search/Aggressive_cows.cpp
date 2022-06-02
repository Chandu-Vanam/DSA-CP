
// Time complexity= 0(n log n)
// space complexity=0(n)


#include<bits/stdc++.h>
bool ispossible(vector<int>&stalls,int cows,int dist)
{
    int k=stalls[0];
    int n=stalls.size();
    cows--;
    
    for(int i=1;i<n;i++)
    {
        if(stalls[i]-k>=dist)
        {
            cows--;
            if(!cows)
                return true;
            
             k=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    
    int minD=stalls[n-1]-stalls[0];
    int ans=INT_MIN;
    
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(ispossible(stalls,k,mid))
            low=mid+1;
        else
            high=mid-1;
    }
    return high;
}
