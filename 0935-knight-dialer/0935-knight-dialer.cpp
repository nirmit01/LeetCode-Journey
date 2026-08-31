class Solution {
public:
    const int mod=1e9+7;
    int knightDialer(int n) {
        vector<long long> dp(10,1);
        for(int i=2;i<=n;i++)
        {
            vector<long long> next(10);
            next[1]=(dp[6]+dp[8])%mod;
            next[2]=(dp[7]+dp[9])%mod;
            next[3]=(dp[4]+dp[8])%mod;
            next[4]=(dp[3]+dp[9]+dp[0])%mod;
            next[5]=0;
            next[6]=(dp[1]+dp[7]+dp[0])%mod;
            next[7]=(dp[2]+dp[6])%mod;
            next[8]=(dp[1]+dp[3])%mod;
            next[9]=(dp[4]+dp[2])%mod;
            next[0]=(dp[4]+dp[6])%mod;
            dp=next;
        }
        long long ans=0;
        for(long long x:dp)
            ans=(ans+x)%mod;
        return ans;
    }
};