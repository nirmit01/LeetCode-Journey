class Solution {
public:
    void findans(int i,int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i==nums.size() || nums[i]>target)
            return;
        
        temp.push_back(nums[i]);
        findans(i+1,target-nums[i],nums,temp,ans);
        temp.pop_back();
        
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[j-1])
            j++;
        findans(j,target,nums,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        findans(0,target,candidates,temp,ans);
        return ans;
    }
};