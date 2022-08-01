#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

void dijkstras(vector<pair<int,int>> *adj, vector<int> &min_dist,int n)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    min_dist[0]=0;
    
    pq.push({0,0});
    
    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        
        // vector<pair<int,int> >::iterator it;
        for(auto it=adj[node].begin();it!=adj[node].end();it++)
        {
            int next=it->first;
            int dist=it->second;
            if(min_dist[next] > dist+min_dist[node])
            {
                min_dist[next] = dist+min_dist[node];
                pq.push({min_dist[next],next});
            }
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
        
        int u,v,wt;
        
        vector<pair<int,int>> adj[MAX];
        vector<int> min_dist(n);
        
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v>>wt;
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        for(int i=0;i<n;i++)
            min_dist[i]=INT_MAX;
        
        dijkstras(adj,min_dist,n);
        
        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<min_dist[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
