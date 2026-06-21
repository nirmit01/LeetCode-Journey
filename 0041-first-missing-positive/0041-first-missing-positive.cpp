class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=n+1;
        }
        for(int i=0;i<n;i++)
        {
            int k=abs(nums[i]);
            if(k<=n)
            {
                if(nums[k-1]>0)
                    nums[k-1]=-nums[k-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};