#include<bits/stdc++.h>
bool checkOverlappingIntervals(long* start, long* end, int n)
{
    //Write your code here 
    sort(start,start+n);
    sort(end,end+n);
    for(int i=1;i<n;i++)
    {
        if(start[i]<end[i-1])
            return true;
    }
    return false;
}
