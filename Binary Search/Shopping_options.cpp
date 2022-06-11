#include<bits/stdc++.h>

int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{ 
    vector<int>sum;
    for(int i=0;i<pants.size();i++)
    {
        for(int j=0;j<shirts.size();j++)
        {
            sum.push_back(pants[i]+shirts[j]);
        }
    }
    
    sort(sum.begin(),sum.end());
    
    int answer=0;
    for(int i=0;i<shoes.size();i++)
    {
        for(int j=0;j<skirts.size();j++)
        {
            int remain=budget-shoes[i]-skirts[j];
            // int ans;
            
            int low=0,high=sum.size()-1;
            while(low<high)
            {
                int mid=(low+high)/2;
                
                if(sum[mid]<=remain)
                    low=mid+1;
                else 
                    high=mid;
            }
             if(low < sum.size() && sum[low] <= remain)
             {
               low++;
            }
            answer+=low;
            
            // auto low=upper_bound(sum.begin(),sum.end(),remain);
            // answer+=(low-sum.begin());
        }
    }
    return answer;
    
	// Write your code here
}
