void dfs(int curr,int par,vector<int>&ans, vector<vector<int>> &adj)
{
    ans[curr]=1;
    
    for(int i=0;i<adj[curr].size();i++)
    {
        if(adj[curr][i]!=par)
        {
            dfs(adj[curr][i],curr,ans,adj);
            ans[curr]+=ans[adj[curr][i]];
        }
    }
}
vector<int> countNodesInAllSubtrees(int n, vector<vector<int>> &adj) {
	// Write your code here.
	// adj[i] will contain all nodes adjacent to the ith node(0-based indexing)
    vector<int>ans(n);
    dfs(0,-1,ans,adj);
    
    return ans;
}
