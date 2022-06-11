#include<bits/stdc++.h>

bool ispossible(vector<int>&boards,int barrier,int k)
{
    int cnt=0;
    int allocated=0;
    for(int i=0;i<boards.size();i++)
    {
        if(boards[i]+allocated>barrier)
        {
            cnt++;
        	allocated=boards[i];
            if(allocated>barrier)
                return false;
        }
        else
        	allocated+=boards[i];
    }
    
    if(cnt<k)
        return true;
    else
        return false;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low=boards[0];
    int high=boards[0];
    for(int i=1;i<boards.size();i++)
    {
        high+=boards[i];
        low=min(low,boards[i]);
    }
    
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(ispossible(boards,mid,k))
            high=mid-1;
        else
            low=mid+1;
    }
    
    return low;
}
