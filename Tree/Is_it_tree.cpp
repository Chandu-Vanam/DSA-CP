#include <bits/stdc++.h>
using namespace std;
#define N 2005

vector<int>adj[N];

bool iscycle(int curr,int par,vector<bool>&visited)
{
    visited[curr]=true;
    
    for(int v:adj[curr])
    {
        if(v!=par)
        {
            if(visited[v])
                return true;
            
            if(!visited[v] && iscycle(v,curr,visited))
            return true;
        }
    }
    return false;
}

bool isTree(int n)
{
    vector<bool>visited(n,false);
    
    if(iscycle(1,0,visited))
        return false;
        
    for(int i=1;i<n;i++)
    if(visited[i]==false)
    {
    	return false;
    } 
    
    return true;
}
int main() {
	int n,m;
	cin >> n>>m;
	
	for(int i=0;i<=n;i++)
        adj[i].clear();
    
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
  
    if(isTree(n))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    
	return 0;
}
