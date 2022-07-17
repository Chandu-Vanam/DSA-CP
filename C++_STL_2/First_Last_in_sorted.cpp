#include<bits/stdc++.h>

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Write your code here.
    // pair<int,int>p;
    
    if(arr.size()==0)
        return {-1,-1};
    
    int start=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    int end = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
    
    if(start>=n)
        return {-1,-1};
    
    if(arr[start]==x)
        return {start,end-1};
    else
        return {-1,-1};
        
}

