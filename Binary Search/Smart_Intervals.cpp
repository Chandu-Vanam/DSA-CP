
// vector<int> smartInterval(vector<vector<int>> &intervals, int n)
// {
// 	// Write your code here.
// }
#include<bits/stdc++.h>
struct sortby
{
    int operator()(const pair<int,int> &p,const int &n)
    {
        if(p.first < n)
            return 1;
        else 
            return 0;
    }
    int operator()(const int &n,const pair<int,int> &p)
    {
        if(n < p.first)
            return 1;
        else 
            return 0;
    }
};

vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
    vector<pair<int,int>> v;
    vector<int> ans(n);
    for(int i = 0;i<n;i++)
        v.push_back(make_pair(intervals[i][0],i));
    sort(v.begin(),v.end());
    for(int i = 0;i<n;i++)
    {
        int ele = intervals[i][1];
        int in = lower_bound(v.begin(),v.end(),ele,sortby()) - v.begin();
        if(in == n)
            ans[i] = -1;
        else 
            ans[i] = v[in].second;
        
    }
    return ans;
}
