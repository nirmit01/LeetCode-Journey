class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot=0;
        for(int i:nums)
            tot+=i;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            int k=tot-nums[i];
            if(k%2==0 && curr==k/2)
            {
                return i;
            }
            curr+=nums[i];
        }
        return -1;
    }
};