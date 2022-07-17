
//  TC- 0(N)
//  SC- 0(N)
  
bool findPath(vector<vector<int>>&tree,int node1,int node2,int par,vector<int>&path)
{
  if(node1==node2)
  {
    path.push_back(node2);
    return true;
  }
  
  for(int i=0;i<tree[node1].size();i++)
  {
    if(tree[node1[i]!=parent)
    {
      if(findPath(tree,tree[node1[i],node2,node1,path))
      {
        path.push_back(node1);
        return true;
      }
    }
 }
     
 return false;
}

void findNode(vector<vector<int>>&tree,int u,int par,int height,int &maxheight,int &node)
{
    if(height>maxheight)
    {
        maxHeight=hieght;
        node=u;
    }

    for(int i=0;i<tree[u].size();++i)
    {
        if(tree[u][i]!=par)
        {
            find(tree,tree[u][i],height+1,maxheight,node);
        }
    }
}


vector<int> center(int n,vector<vector<int>>&edges)
{
    vector<vector<int>>tree(n);
    for(int i=0;i<n-1;++i)
    {
        tree[edges[i][0]].push_back(edges[i][0]);
        tree[edges[i][1]].push_back(edges[i][1]);        
    }
    
    int maxheight=-1;
    int node1=-1;

    findNode(tree,0,-1,0,maxheight,node1);

    maxheight=-1;
    ind node2=-1;

    findNode(tree,node1,-1,0,maxheight,node2);

    vector<int>path;

    findPath(tree,node1,node2,-1,path);

    vector<int>res;

    if(path.size() % 2)
    {
        res.push_back(path[path.size()/2]);
    }
    else
    {
        int c1=path[path.size()/2];
        int c2=path[(path.size()-1)/2];
        res.push_back(min(c1,c2));
        res.push_back(max(c1,c2));
    }

    return res;
}                         

