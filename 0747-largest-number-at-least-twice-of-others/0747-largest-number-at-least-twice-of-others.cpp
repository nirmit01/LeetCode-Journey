class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int max1=-1,max2=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max1)
            {
                max2=max1;
                max1=nums[i];
                ans=i;
            }
            else if(nums[i]>max2)
            {
                max2=nums[i];
            }
        }
        if(2*max2>max1)
            return -1;
        return ans;
    }
};