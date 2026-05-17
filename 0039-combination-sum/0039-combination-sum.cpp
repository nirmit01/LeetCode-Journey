class Solution {
private:
    void findans(int i, int target, vector<int>& nums, vector<int>&temp,vector<vector<int>>& ans)
    {
        if(i==nums.size())
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(nums[i]<=target)
        {
            temp.push_back(nums[i]);
            findans(i,target-nums[i],nums,temp,ans);
            temp.pop_back();
        }
        findans(i+1,target,nums,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findans(0,target,candidates,temp,ans);
        return ans;
    }
};