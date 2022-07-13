class DSU{
  vector<int>parent;
    vector<int>subtree;
    int N;

    public:
    DSU(int n)
    {
        N=n;
        parent=vector<int>(N+1,0);
        subtree=vector<int>(N+1,1);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    
    int findRoot(int u)
    {
        while(u!=parent[u])
        {
            parent[u]=parent[parent[u]];
            u=parent[u];
        }
        
        return u;
    }
    
    bool combine(int u,int v)
    {
        int ru=findRoot(u);
        int rv=findRoot(v);
        
        if(ru==rv)
            return false;
        
        if(subtree[ru]>subtree[rv])
        {
            parent[rv]=ru;
            subtree[ru]+=subtree[rv];
        }
        else
        {
            parent[ru]=rv;
            subtree[rv]+=subtree[ru];
        }
        
        return true;
    }
};
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    DSU dsu=DSU(n);
    bool iscyclefound=false;
    
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        
        if(!dsu.combine(u,v))
            iscyclefound=true;
    }
    
    if(iscyclefound)
        return "Yes";
    else
        return "No";
}
