class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)   return false;
        int tgt=sum/2;
        bitset<10001> dp;
        dp[0]=1;
        for(int i:nums)
        {
            dp |= dp<<i;
            if(dp[tgt])
                return true;
        }
        return dp[tgt];
    }
};