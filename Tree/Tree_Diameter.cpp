#include<bits/stdc++.h>
using namespace std;

#define N (int)(1e4+5)

int height[N];
vector<int> tree[N];
int max_ht[N];

int res=0;

void makeEdge(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void dfs(int curr,int par,int ht=0)
{
    height[curr]=ht;
    max_ht[curr]=ht;
    
    int fmax=0;
    int smax=0;
    
    for(auto u:tree[curr])
    {
        if(u==par)
            continue;
        
        dfs(u,curr,ht+1);
        
        max_ht[curr]=max(max_ht[curr],max_ht[u]);
        
        if(max_ht[u]>fmax)
        {
            smax=fmax;
            fmax=max_ht[u];
        }
        else if(max_ht[u]>smax)
        {
            smax=max_ht[u];
        }
    }
    
    int max_dist=max(0,max(fmax-ht,fmax+smax-2*ht));
    res=max(res,max_dist);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<=n;i++)
        {
            tree[i].clear();
            height[i]=max_ht[i]=0;
        }
        
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            
            makeEdge(u,v);
        }
        
        res=0;
        dfs(1,0);
        
        cout<<res<<endl;
    }
    return 0;
}
