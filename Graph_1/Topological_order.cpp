#include<bits/stdc++.h>

vector<int> adj[1005];
vector<int>in(1005);

void bfs(int src,vector<int>&ans,int nodes)
{
	queue<int>q;
    
    for(int i=0;i<nodes;i++)
        if(in[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        ans.push_back(u);
        
        for(int v:adj[u])
        {
            // if(in[v]>0)
                in[v]--;
            
            if(in[v]==0)
                q.push(v);
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    
    for(int i=0;i<=nodes;i++)
    {
        in[i]=0;
        adj[i].clear();
    }
    
    for(int i=0;i<graph.size();i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
        in[graph[i][1]]++;
    }
    
    vector<int>ans;
    
    bfs(0,ans,nodes);
    // for(int i=0;i<nodes;i++)
    //     cout<<ans[i]<<" ";
    // cout<<endl;
    
    return ans;
}
