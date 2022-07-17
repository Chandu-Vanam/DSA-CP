#include<bits/stdc++.h>
int maxArea(vector<int>& height) {
    // Write your code here.
    
    int ans=0,left=0,right=height.size()-1;
    
    while(left<right)
    {
        ans=max(ans,min(height[left],height[right])*(right-left));
        
        if(height[left]>height[right])
            right--;
        else if(height[left]<height[right])
            left++;
        else
        {
            right--;
            left++;
        }
    }
    
    return ans;
}
