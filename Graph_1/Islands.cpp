#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
vector<bool>visited(1005);

void dfs(int u)
{
    visited[u]=true;
    
    for(int v:adj[u])
    {
        if(!visited[v])
            dfs(v);
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
        
        for(int i=0;i<=n;i++)
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
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                cnt++;
                dfs(i);
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}
