/*
    Time Complexity: O(N + log(P))
    Space Complexity: O(N)

    Where 'N' is the given integer 'n',
    'P' is the given integer 'p'.
*/

// Iterative Function to calculate (x ^ y) % p.
unsigned long long  power(int x, int y, int p)
{

    // Initialize ans.
    unsigned long long  ans = 1;

    // If x is more than or equal to p then update x.
    x = x % p;

    while (y > 0)
    {

        // If y is odd, multiply x.
        if (y % 2 != 0)
        {
            ans = (ans * x) % p;
        }

        // For even y.
        y = y / 2;
        x = (x * x) % p;
    }

    return ans;
}

// Returns n ^ (- 1) mod p
unsigned long long  powInverse(int n, int p)
{
    return power(n, p - 2, p);
}

unsigned long long  fermatLittle(int n, int r, int p)
{

    if (n < r)
    {
        return 0;
    }

    // Base case
    if (r == 0)
    {
        return 1;
    }

    // Make dp array to store the value of factorial of number modulo p.
    unsigned long long  dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i % p;
    }

    return (dp[n] * powInverse(dp[r], p) % p * powInverse(dp[n - r], p) % p) % p;
}
