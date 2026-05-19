class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int k=prices[i+1]-prices[i];
            if(k>0)
            {
                ans+=k;
            }
        }
        return ans;
    }
};