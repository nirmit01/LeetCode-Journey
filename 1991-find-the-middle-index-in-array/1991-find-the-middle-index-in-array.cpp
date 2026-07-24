class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int tot=0;
        for(int i:nums)
            tot+=i;
        int curr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(curr==tot-curr-nums[i])
                return i;
            curr+=nums[i];
        }
        return -1; 
    }
};