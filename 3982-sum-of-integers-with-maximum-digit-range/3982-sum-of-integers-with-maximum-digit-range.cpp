class Solution {
public:
    int solve(int x)
    {
        int maxi=0,mini=10;
        while(x>0)
        {
            int k=x%10;
            maxi=max(maxi,k);
            mini=min(mini,k);
            x/=10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int ans=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            int k=solve(nums[i]);   
            if(k>maxi)
            {
                maxi=k;
                ans=nums[i];
            }
            else if(k==maxi)
                ans+=nums[i];
        }
        return ans;
    }
};