class Solution {
private:
    int ans(int low,int high, vector<int>& nums)
    {
        if(low==high)
        {
            return nums[low];
        }
        if(nums[low]<nums[high])
        {
            return nums[low];
        }
        else
        {
            int mid=low+(high-low)/2;
            return min(ans(low,mid,nums),ans(mid+1,high,nums));
        }
    }
public:
    int findMin(vector<int>& nums) {
        return ans(0,nums.size()-1,nums);
    }
};