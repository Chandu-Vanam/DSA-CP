
  TC- 0(n)
  SC- 0(1)

int decodingDigits(string seq)
{
    // Write your code here.
    seq="$"+seq;
    int n=seq.size();
    long long dp[n];
    const int mod=(int)(1e9+7);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<n;i++)
    {
        dp[i]=0;
        
        if(seq[i]!='0')
            dp[i]=dp[i-1];
        
        int num=(int)(seq[i-1]-'0')*10 + (int)(seq[i]-'0');
        if(num>=10 && num<=26)
            dp[i]+=dp[i-2];
        
        dp[i]%=mod;
            
    }
    
    return dp[n-1];
}
