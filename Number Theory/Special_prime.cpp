#include<bits/stdc++.h>
using namespace std;
vector<int> primes;

void SieveofEratosthenes(int n, bool visited[])
{
    
    for(int i=0;i<(n+1);i++)
        visited[i] = true;
    
    for (int i = 2; i*i <n + 1; i++){
        if (visited[i]) {
            for (int j = i * i; j < n + 1; j += i)
                visited[j] = false;
        }
    }
    
    for(int i=2;i<(n+1);i++)
    {
        if(visited[i])
            primes.push_back(i);
    }
}
void specialPrimes(int n)
{
    bool visited[n+1];
    SieveofEratosthenes(n, visited);
    int count = 0;
    for (int i = 1; i < primes.size(); i++) {
        int a = primes[i] + primes[i - 1] + 1;
        if(a <= n && visited[a])
            count++;
    } 
    cout<<count;
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    specialPrimes(n);
    return 0;
}
