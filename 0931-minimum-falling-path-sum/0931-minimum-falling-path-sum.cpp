class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp=matrix;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int k=dp[i-1][j];
                if(j>0)
                    k=min(k,dp[i-1][j-1]);
                if(j<n-1)
                    k=min(k,dp[i-1][j+1]);
                dp[i][j]+=k;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};