#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int INF=1e9;

struct Edge{
  	int u;
    int v;
    long long w;
};

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,ed;
        cin>>n>>ed;
        
        int src,des;
        cin>>src>>des;
        
    	Edge edgeList[N+1];
        
        for(int i=1;i<=ed;i++)
        {
			cin>>edgeList[i].u>>edgeList[i].v>>edgeList[i].w;
        }
        
        vector<long long>dist(N+1);
        
        for(int i=1;i<=n;i++)
        	dist[i]=INF;
        
        dist[src]=0;
        
        for(int i=1;i<n;i++)
        {
            bool flag=false;
            for(int j=1;j<=ed;j++)
            {
                Edge e=edgeList[j];
                
                if(dist[e.u]!=INF && dist[e.v]>dist[e.u]+e.w)
                {
                    flag=true;
                    dist[e.v]=dist[e.u]+e.w;
                }
            }
            
            if(!flag)
                break;
        }
        cout<<dist[des]<<endl;
    }
    return 0;
}
