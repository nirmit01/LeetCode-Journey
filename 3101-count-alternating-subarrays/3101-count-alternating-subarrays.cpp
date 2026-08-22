class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> dp(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
                dp[i]+=dp[i-1];
        }
        long long ans=0;
        for(int i:dp)
            ans+=i;
        return ans;
    }
};