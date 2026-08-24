class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(sz+2,vector<int>(sz+2));
        for(int i=sz;i>=1;i--)
        {
            for(int j=i;j<=sz;j++)
            {
                int mini=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    mini=min(mini, cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][sz];
    }
};