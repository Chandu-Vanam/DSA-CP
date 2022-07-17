#include<bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    vector<int>ans;
    
   int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum=0;
        for(int j=i;j<arr.size();j++)
        {
            sum+=arr[j];
            ans.push_back(sum);
        }
    }
    
    sort(ans.begin(),ans.end());
    // for(auto x:ans)
    // cout<<x<<" ";

    while(k!=1)
    {
        ans.pop_back();
        k--;
    }
    
	 // int a=1;
    return ans.back();
}
