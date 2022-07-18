#include<bits/stdc++.h>
using namespace std;

void dfs(int u,vector<bool>&visited,vector<int>adj[])
{ 
    visited[u]=true;
    for(int v:adj[u])
    {
        if(visited[v]==false)
        {
            dfs(v,visited,adj);
        }
    }
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        
        vector<int>adj[1005];
        vector<bool>visited(1005);
        
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
            adj[i].clear();
        }
        
        int u,v;
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int v1,v2;
        cin>>v1>>v2;
        
        dfs(v1,visited,adj);
          
        if(visited[v2])
            cout<<"true\n";
        else
            cout<<"false\n";
    }
    return 0;
}
