class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxi(n),mini(n),ans(n);
        maxi[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mini[i]=min(mini[i+1],nums[i]);
        }
        ans[n-1]=maxi[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(maxi[i]>mini[i+1])
            {
                ans[i]=ans[i+1];
            }
            else
            {
                ans[i]=maxi[i];
            }
        }
        return ans;
    }
};