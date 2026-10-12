class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod=1e9+7;
        vector<int> bits(30);
        for(int x:nums)
        {
            for(int i=0;i<30;i++)
            {
                if(x & (1<<i))
                    bits[i]++;
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            long long x=0;
            for(int j=0;j<30;j++)
            {
                if(bits[j])
                {
                    x|=(1ll<<j);
                    bits[j]--;
                }
            }
            ans = (ans+ x*x)%mod;
        }
        return ans;
    }
};