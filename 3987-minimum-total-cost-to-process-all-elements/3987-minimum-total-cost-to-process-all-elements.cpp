class Solution {
public:
    const int mod=1e9+7;
    const int inv2=500000004;
    int minimumCost(vector<int>& nums, int k) {
        long long cost=0,curr=k;
        for(int x:nums)
        {
            if(curr<x)
            {
                int diff=x-curr;
                int req= (diff%k) ? diff/k+1 : diff/k;
                cost+=req;
                curr= (curr+req*k)-x;
            }
            else
            {
                curr-=x;
            }
        }
        return (cost%mod)*((cost+1)%mod)%mod*inv2%mod;
    }
};