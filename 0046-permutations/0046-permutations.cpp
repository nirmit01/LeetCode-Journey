class Solution {
public:
    void solve(vector<vector<int>>& ans, int x, vector<int>& nums)
    {
        if(x==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        int n=nums.size();
        for(int i=x;i<n;i++)
        {
            swap(nums[x],nums[i]);
            solve(ans,x+1,nums);
            swap(nums[x],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,0,nums);
        return ans;
    }
};