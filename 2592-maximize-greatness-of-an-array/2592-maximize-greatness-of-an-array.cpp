class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[j])
            {
                ans++;
                j++;
            }
        }
        return ans;
    }
};