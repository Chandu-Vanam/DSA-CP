void solve(vector<vector<bool>>&arr,vector<vector<int>>&visited,int n,int i,int j,string str,vector<string>&ans)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(str);
        return;
    }
    
    if(i+1<n && visited[i+1][j]!=1 && arr[i+1][j])
    {
        visited[i][j]=1;
        solve(arr,visited,n,i+1,j,str+'D',ans);
        visited[i][j]=0;
    }
    
    if(j+1<n && visited[i][j+1]!=1 && arr[i][j+1])
    {
        visited[i][j]=1;
        solve(arr,visited,n,i,j+1,str+'R',ans);
        visited[i][j]=0;
    }
    
    if(i-1>=0 && visited[i-1][j]!=1 && arr[i-1][j])
    {
        visited[i][j]=1;
        solve(arr,visited,n,i-1,j,str+'U',ans);
        visited[i][j]=0;
    }
    
    if(j-1>=0 && visited[i][j-1]!=1 && arr[i][j-1])
    {
        visited[i][j]=1;
        solve(arr,visited,n,i,j-1,str+'L',ans);
        visited[i][j]=0;
    }
}
vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    int n=arr.size();
	vector<vector<int>>visited(n,vector<int>(n,0));
    vector<string>ans;
    
    if(arr[0][0])
        solve(arr,visited,n,0,0,"",ans);
    
    return ans;
}
