class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n=nums.size(),l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]>threshold)
            {
                l=r+1;
                continue;
            }
            if(nums[r]%2 && r==l)
                l++;
            
            if(r>0 && nums[r]%2==nums[r-1]%2)
            {
                if(nums[r]%2)
                    l=r+1;
                else
                    l=r;
            }
            ans=max(ans,r-l+1); 
        }
        return ans;
    }
};