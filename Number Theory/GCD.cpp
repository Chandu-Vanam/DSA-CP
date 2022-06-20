
// Time Complexity:0(log(min(a,b))
// Space complexity:0(1)

int solve(int a,int b)
{
    // if(a==0)
    //     return b;
    
    if(b==0)
        return a;
    
    //if a is greater tha b ,we take a%b as it gives remainder whhich we get after doing a-b,b or b-a,a method 
    // we skip all those method and directly take a%b
    //if a is smaller we simply swap
    //every time we keep a as bigger than b
    // if(a<b)
        return solve(b,a%b);
    // else
    //     return solve(a%b,b);
}

--------------------------------------------------------------------------------
int solve(int a,int b)
{
    if(a==0)
        return b;
    
    if(b==0)
        return a;
    
    //if a is greater tha b ,we take a%b as it gives remainder whhich we get after doing a-b,b or b-a,a method 
    // we skip all those method and directly take a%b
    //if a is smaller we simply swap
    //every time we keep a as bigger than b
    if(a<b)
        return solve(b,a);
    else
        return solve(a%b,b);
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        
        cout<<solve(x,y)<<endl;
    }
    return 0;
}
