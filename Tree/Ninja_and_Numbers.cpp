// int kthAncestor(int n, vector<int> & parent, int node, int k)
// {
//     // Write your code here.
//     while(k--)
//     {
//         node=parent[node];
//         if(node==-1)
//             break;
//     }
    
//     return node;
// }


Another Apporach


int par[1003][20];

vector<vector<int> > graph;

// Utility function for preprocessing using binary lifting concept
void dfs(int src = 0,int p = -1,int h = 0)
{
    if(p != -1)
    {
      par[src][0] = p;
      for(int j = 1; (1 << j) <= h; j++)
      {
         par[src][j] = par[par[src][j - 1]][j - 1];
      }
    }

    for(int i = 0; i < graph[src].size(); i++)
    {
        if(graph[src][i] == p)
        {
            continue;
        }
            
         dfs(graph[src][i], src, h + 1);
    }
}

// Utility function that returns the k-th ancestor.
int getKthAncestor(int node, int k) {
    
    for(int i = 31; i >= 0; i--)
    {
        if(node == -1)
        {
            break;
        }

        if((1 << i) & k)
        {
            node = par[node][i];
        }
    }

    return node;
}

int kthAncestor(int n, vector<int> parent, int node, int k)
{
    // Resize graph to size 'n'
    graph.resize(n);
    
    // Run through all parents and create graph considering edge b/w 'i' and parent[i]
    for(int i = 1;i < parent.size(); ++i)
    {
        int u = parent[i];

        graph[u].push_back(i);
    }

    memset(par, -1, sizeof(par));

    // Preprocessing
    dfs();

    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
    }

    // Call helper function
    return getKthAncestor(node, k);
}
