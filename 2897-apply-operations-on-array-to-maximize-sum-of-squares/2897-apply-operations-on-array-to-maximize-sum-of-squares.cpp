class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(31);
        for(int x:nums)
        {
            for(int i=0;i<31;i++)
            {
                if(x & (1<<i))
                    bits[i]++;
            }
        }
        long long ans=0;
        const int mod=1e9+7;
        for(int i=0;i<k;i++)
        {
            long long x=0;
            for(int j=0;j<31;j++)
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