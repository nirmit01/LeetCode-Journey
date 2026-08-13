class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxi=1,ind=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && (dp[i]<dp[j]+1))
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(ind!=-1)
        {
            ans.push_back(nums[ind]);
            ind=parent[ind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};