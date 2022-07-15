#include<bits/stdc++.h>
#define N (int)(1e5+5)

vector<int> adj[N];
int subtree[N];

void dfs(int curr,int par)
{
    subtree[curr]=curr;
    
    for(int v:adj[curr])
    {
        if(v!=par)
        {
            dfs(v,curr);
            subtree[curr]^=subtree[v];
        }
    }
}

vector<int> XORquery(int n, vector<vector<int>> &edges, int q, vector<int> &query) {
    // Write your code here.	
    
    for(int i=0;i<=n;i++)
    {
        subtree[i]=0;
        adj[i].clear();
    }
        
    
	for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(0,0);
    
    vector<int>res; 
    for(int i=0;i<query.size();i++)
    {
        res.push_back(subtree[query[i]]);
    }
    
    return res;
}
