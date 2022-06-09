#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int i=0;
        while((n&(1<<i))==0)
            i++;
        
        cout<<(n&(1<<i))<<endl;
    }
    return 0;
}
