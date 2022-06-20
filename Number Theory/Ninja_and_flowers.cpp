
// Time complexity: 0(N)
// Space Complexity: 0(N)

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    for(int i=2;i*i<=n+1;i++)
    	if(n%i==0)
        return false;
    return true;
}

void sieve(int n,set<int>&primes,set<int>&non_primes,bool visited[])
{
    for(int i=2;i*i<=n+1;i++)
    {
        if(isprime(i))
        {
            // primes.push_back(i);
            for(int j=i*i;j<=n+1;j+=i)
            {
                non_primes.insert(j);
                visited[j]=true;
            }
        }
    }
    
    for(int i=2;i<=n+1;i++)
        if(visited[i]==false)
            primes.insert(i);
}
int main(){
    
    int n;
    cin>>n;
    
    bool visited[n+2]={false};
    set<int>primes;
    set<int>non_primes;
    
    sieve(n,primes,non_primes,visited);
    
//     for(auto x:primes)
//         cout<<x<<" ";
    
//     cout<<endl;
//      for(auto y:non_primes)
//         cout<<y<<" ";
    int box1=primes.size();
    int box2=non_primes.size();
    cout<<2<<endl;
    
    if(box1<box2)
        cout<<box1<<" "<<box2<<endl;
    else
        cout<<box2<<" "<<box1<<endl;
    
    return 0;
}
