class Solution {
public:

    int solve(int l,int r, vector<int>& nums,vector<vector<int>>& dp)
    {
        if(l==r)
            return dp[l][r]=nums[l];
        if(dp[l][r]!=INT_MIN)
            return dp[l][r];
        
        return dp[l][r]=max(nums[l]-solve(l+1,r,nums,dp),nums[r]-solve(l,r-1,nums,dp));

    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return solve(0,n-1,nums,dp)>=0;
    }
};