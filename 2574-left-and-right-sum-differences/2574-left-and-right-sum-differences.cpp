class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n),v(n);
        for(int i=n-2;i>=0;i--)
            v[i]=v[i+1]+nums[i+1];
        int curr=0;
        ans[0]=v[0];
        for(int i=1;i<n;i++)
        {
            curr+=nums[i-1];
            ans[i]=abs(curr-v[i]);
        }
        return ans;
    }
};