class Solution {
public:
    int ans=0;
    void solve(int i, int curr, vector<int>& nums)
    {
        if(i==nums.size())
        {
            ans+=curr;
            return;
        }
        solve(i+1,curr,nums);
        solve(i+1,curr^nums[i],nums);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0,0,nums);
        return ans;
    }
};