#include<vector>

vector<int>visited(1001);
vector<int>adj[1001];

bool dfs(int u)
{
    visited[u]=1;
    
    for(int v:adj[u])
    {
        if(visited[v]==1)
            return true;
         else 
         {
             if(visited[v]==0)
            {
                bool flag=dfs(v);
                if(flag)
                return true;
            }
         }
    }
    
    visited[u]=2;
    return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	for(int i=0;i<=v;i++)
    {
        visited[i]=0;
        adj[i].clear();
    }
 	
    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i=0;i<v;i++)
    {
        if(dfs(i))
            return true;
    }
    
    return false;
}
