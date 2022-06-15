
Time Complexity - 0(N*log(log(N))
Space Complexity - 0{N)

bool isprime(int n)
{
    if(n==1)
        return false;
    
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    
    return true;
}

vector<int> primeNumbersTillN(int N) 
{ 
 	// Write your code here
    vector<int>prime(N+1);
    vector<int>ans;
    
    for(int i=1;i<=N;i++)
        prime[i]=true;
    
    prime[1]=false;
    
    for(int i=2;i*i<=N;i++)
    {
        if(isprime(i))
        {
            for(int j=i*i;j<=N;j+=i)
            prime[j]=false;
        }
    }
    
    for(int i=0;i<=N;i++)
    {
        if(prime[i]==true)
            ans.push_back(i);
    }
    return ans;
}
