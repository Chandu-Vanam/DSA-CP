#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
struct Edge{
  	int u;
    int v;
    int wt;
};

bool mycmp(Edge &a,Edge &b)
{
    return a.wt<b.wt;
}

int find_set(int curr,vector<int>&par)
{
    if(par[curr]==-1)
        return curr;
    
    return par[curr]=find_set(par[curr],par);
}

void union_set(int x,int y,vector<int>&par,vector<int>&rank)
{
    int fx=find_set(x,par);
    int fy=find_set(y,par);
    
    if(rank[fx]>rank[fy])
    {
        rank[fx]+=rank[fy];
        par[fy]=fx;
    }
    else
    {
        rank[fy]+=rank[fx];
        par[fx]=fy;
    }
}

int main(){
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        
        int x,y,z;
        vector<Edge>tree(MAX);
		vector<int>par(MAX);
		vector<int>rank(MAX);
        
        for(int i=0;i<=v;i++)
        {
            par[i]=-1;
            rank[i]=1;
        }
        
        for(int i=0;i<e;i++)
        {
        	cin>>x>>y>>z;
            
            tree[i].u=x;
            tree[i].v=y;
            tree[i].wt=z;
        }
        
        sort(tree.begin(),tree.end(),mycmp);
   
        int ans=0;
        
        for(auto it:tree)
        {
            int n1=find_set(it.u,par);
            int n2=find_set(it.v,par);
            if(n1!=n2)
            {
                int a=it.u;
                int b=it.v;
                union_set(a,b,par,rank);
                ans+=it.wt;
            }
        }
        
        cout<<ans<<endl;
    }
    // write your code here
    return 0;
}
