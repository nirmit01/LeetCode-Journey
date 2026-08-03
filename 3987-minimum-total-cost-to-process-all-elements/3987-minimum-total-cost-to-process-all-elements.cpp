class Solution {
public:
    const int mod=1e9+7;
    const int inv2=500000004;
    int minimumCost(vector<int>& nums, int k) {
        long long summ=0;
        for(int x:nums)
            summ+=x;
        long long cost= (summ-1)/k;

        return (cost%mod)*((cost+1)%mod)%mod*inv2%mod;
    }
};