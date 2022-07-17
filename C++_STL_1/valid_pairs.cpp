bool CheckSumPairs(int ar[], int n, int k, int m) {
	/*Write your code here. 
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	f*/ 
    if(n%2!=0)
        return false;
    
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[ar[i]%k]++;
    }
    
    for(int i=0;i<n;i++)
    {
        int r1=mp[ar[i]%k];
        int r2;
        if(ar[i]%k<=m)
            r2=mp[m-(ar[i]%k)];
        else
            r2=mp[(k-(ar[i]%k))+m];
        
        if(r1!=r2)
            return false;
    }
    
    return true;
}
