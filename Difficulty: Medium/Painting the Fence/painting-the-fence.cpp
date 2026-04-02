const int mod = 1e9 + 7;
class Solution {
  public:
    long long countWays(int n, long long k) {
        // code here
        if (n == 1) return k % mod;
        if (n == 2) return (k * k) % mod;
        
        vector<long long> dp(n + 1, -1);
        
        dp[1] = k % mod;
        dp[2] = (k * k) % mod;
        
        for (int i = 3; i <= n; ++i) {
            long long same = dp[i - 1] * (k - 1) % mod;
            long long diff = dp[i - 2] * (k - 1) % mod;
            
            dp[i] = (same + diff) % mod;
        }
        
        return dp[n];
    }
};