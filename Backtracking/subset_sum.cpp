#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int sum,int ind,int cnt)
{
    if(ind==n)
    {
        if(sum==0)
            cnt++;
        
        return cnt;
    }
    cnt=solve(arr,n,sum-arr[ind],ind+1,cnt);
    cnt=solve(arr,n,sum,ind+1,cnt);
    return cnt;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        // sort(arr,arr+n);
        
        int cnt=0;
        cnt=solve(arr,n,sum,0,0);
        cout<<cnt<<endl;
        
    }
    return 0;
}
