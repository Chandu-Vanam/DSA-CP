void toh(int n,int src,int aux,int des,vector<vector<int>>&ans)
{
    if(n==0)
        return;
    
    toh(n-1,src,des,aux,ans);
	vector<int>tmp;
    tmp.push_back(src);
    tmp.push_back(des);
    ans.push_back(tmp);
    toh(n-1,aux,src,des,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code he
    vector<vector<int>> ans;
	
    toh(n,1,2,3,ans);
    
    return ans;
}
