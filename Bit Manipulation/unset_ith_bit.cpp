#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,i;
        cin>>n>>i;
        
        // int bit=(1<<i);
        if(n&(1<<i))
        {
            cout<<(n&~(1<<i))<<endl;
        }
        else
            cout<<n<<endl;
    }
    return 0;
}
