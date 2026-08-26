class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            int maxi=-1;
            int best=0;
            for(int j=1;j<=k && (i-j)>=0;j++)
            {
                maxi=max(maxi, arr[i-j]);
                best=max(best,dp[i-j]+maxi*j);
            }
            dp[i]=best;
        }
        return dp[n];
    }
};