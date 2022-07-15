#include<bits/stdc++.h>

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    // Write your code here.
    vector<int>adjA[n];
    vector<int>adjB[n];
    
    for(int i=0;i<n-1;i++)
    {
        adjA[edgesA[i][0]].push_back(edgesA[i][1]);
        adjB[edgesB[i][0]].push_back(edgesB[i][1]);
    }
    
    for(int u=0;u<n-1;u++)
    {
       	vector<int>a=adjA[u];
    	vector<int>b=adjB[u];
        
        reverse(a.begin(),a.end());
        
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
             return false;   
        }
    }
    
    return true;
}
