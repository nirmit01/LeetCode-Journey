class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]!=-1)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(abs(nums[i]-nums[j])<=target)
                    {
                        dp[j]=max(dp[i]+1,dp[j]);
                    }
                }
            }
        }
        return dp[n-1];
    }
};