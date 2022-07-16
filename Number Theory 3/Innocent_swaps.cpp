#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 1000010

int fact[N];
inline ll multiply(ll a,ll b)
{
    ll x=a;
    x*=ll(b);
    if(x>=mod)
        x%=mod;
    return x;
}

ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    
    ll x=power(a,b/2);
    ll y=(x*x)%mod;
    
    if(b%2)
        return (a*y)%mod;
    return y%mod;
}

void pre_compute()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=multiply(fact[i-1],i);
}

int main(){
    
    // write your code here
    pre_compute();
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
        int ans=multiply(fact[n],power(fact[k],mod-2));
        ans=multiply(ans,power(fact[n-k],mod-2));
        ans=multiply(ans,power(2LL,ll(k)));
        cout<<ans<<endl;
    }
    return 0;
}
