#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int N=1e2;

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        
        int graph[N+1][N+1];
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                graph[i][i]=0;
                else
                graph[i][j]=INF;
            }
        }
        
        int u,v,w;
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v>>w;
            
            if(graph[u][v]==INF || graph[u][v]>w)
            graph[u][v]=graph[v][u]=w;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int a=1;a<=n;a++)
            {
                for(int b=1;b<=n;b++)
                    if(graph[a][i]!=INF && graph[i][b]!=INF)
                    graph[a][b]=min(graph[a][b],graph[a][i]+graph[i][b]);
            }
        }
        
        int q;
        cin>>q;
        
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            
            if(graph[a][b]>graph[b][a])
                cout<<graph[b][a]<<endl;
            else
                cout<<graph[a][b]<<endl;
        }
    }
    return 0;
}
