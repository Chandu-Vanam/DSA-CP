// time complexity : 0(N*(log(log(N)))
// Space complexity : 0(N)

#include <bits/stdc++.h> 
using namespace std; 

int solve(int n) 
{ 
    bool isPrime[n + 1]; 
    memset(isPrime, true, sizeof(isPrime)); 
    int primeCount[n + 1]; 
    memset(primeCount, 0, sizeof(primeCount)); 
    for (int i = 2; i <= n; i++) 
    { 
        if (isPrime[i] == true) 
        { 
            for (int j = 2; j * i <= n; j++) 
            { 
                isPrime[i * j] = false; 
                primeCount[i * j]++; 
            } 
        } 
    } 
    
    int ans = 0; 
    for (int i = 1; i <= n; i++) 
    { 
        if (primeCount[i] == 2) 
        { 
            ans++; 
        } 
    } 
    return ans; 
} 
int main() 
{ 
    int n; 
    cin >> n; 
    cout << solve(n) << endl; 
}
