#include<bits/stdc++.h>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    
//     vector<pair<int,int>>ans;
// 	// Write your code here. 
//     if(arr.size()<=1)
//     {
//         ans.push_back({-1,-1});
//         return ans;
//     }
//         // return ans;
    
//     unordered_set<int>s;
//     for(int i=0;i<n;i++)
//     {
//         auto it=s.find(target-arr[i]);
//         if(it!=s.end())
//         {
//             ans.push_back({arr[i],target-arr[i]});
//             // return ans;
//         }
//         s.insert(arr[i]);
//     }
    
       unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        map[arr[i]]++;
    }
    vector<pair<int, int>> ans;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] + arr[i] == target)
        { 
            if(map[arr[i]] > 1) 
            {
                ans.push_back({arr[i], arr[i]});
                map[arr[i]] -= 2;
            }
        }
        else if(map[target - arr[i]] > 0 && map[arr[i]] > 0) {
            ans.push_back({arr[i], target - arr[i]});
            map[arr[i]] -= 1;
            map[target - arr[i]] -= 1;
        }
    }
    if(ans.size() == 0)
        ans.push_back({-1, -1});
//     return ans;
// }
    // if(ans.empty())
    // {
    //      ans.push_back({-1,-1});
    //     // return ans;
    // }
    // else
    return ans;
}
