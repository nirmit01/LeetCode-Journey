class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            for(int x=1;x*x<=i;x++)
            {
                if(dp[i-x*x]==false)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};