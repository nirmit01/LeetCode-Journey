class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mini=nums[high];
        while(low<n && nums[low]==nums[high])
        {
            low++;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid])
            {
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else
            {
                mini=min(nums[mid],mini);
                high=mid-1;
            }
        }
        return mini;
    }
};