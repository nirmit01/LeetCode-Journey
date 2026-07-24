class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot=0, n=nums.size();
        for(int i:nums)
            tot+=i;
        long long cnt=0,curr=0;
        for(int i=0;i<n-1;i++)
        {
            curr+=nums[i];
            if(curr>=(tot-curr))
                cnt++;
        }
        return cnt;
    }
};