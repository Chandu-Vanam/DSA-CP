#include<bits/stdc++.h>
using namespace std;
#define N 1005

int adj[N][N];
vector<bool>visited(N);

void bfs(int curr,int n)
{   
    queue<int>q;
    q.push(curr);
    
    visited[curr]=true;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
       	cout<<u<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(i==curr)
                continue;
            
            if(adj[u][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){
    
    // write your code here
    int n,e;
    cin>>n>>e;
    
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
        for(int  j=0;j<=n;j++)
            adj[i][j]=0;
    }

    int u,v;
    for(int i=1;i<=e;i++)
    {
        cin>>u>>v;https://lh5.googleusercontent.com/-gOMgsERTEW4/AAAAAAAAAAI/AAAAAAAAAC4/EEALcT_YVSY/s96-c/photo.jpg
        
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    for(int i=0;i<n;i++)
    if(visited[i]==false)
   	bfs(i,n);

    return 0;
}
