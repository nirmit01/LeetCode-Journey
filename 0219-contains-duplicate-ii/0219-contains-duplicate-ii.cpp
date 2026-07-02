class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mpp.count(nums[i]))
            {
                if((i-mpp[nums[i]].back())<=k)
                    return true;
                mpp[nums[i]].push_back(i);
            }
            else
            {
                mpp[nums[i]].push_back(i);
            }
        }
        return false;
    }
};