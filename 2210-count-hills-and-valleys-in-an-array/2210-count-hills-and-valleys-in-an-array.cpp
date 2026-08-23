class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int i=1, n=nums.size();
        int prev=nums[0];
        while(i<n-1)
        {
            int j=i+1;
            while(j<n && nums[i]==nums[j])
                j++;
            if(j==n)
                break;
            if(nums[i]>prev && nums[i]>nums[j])
                ans++;
            else if(nums[i]<prev && nums[i]<nums[j])
                ans++;
            
            prev=nums[i];
            i=j;
        }
        return ans;
    }
};