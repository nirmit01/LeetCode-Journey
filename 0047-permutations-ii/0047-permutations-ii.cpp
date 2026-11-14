class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,vector<bool>& used,vector<vector<int>>& ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
                continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1])
                continue;
            
            used[i]=true;
            temp.push_back(nums[i]);
            solve(nums,temp,used,ans);
            used[i]=false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(n);
        sort(nums.begin(),nums.end());
        solve(nums,temp,used,ans);
        return ans;
    }
};