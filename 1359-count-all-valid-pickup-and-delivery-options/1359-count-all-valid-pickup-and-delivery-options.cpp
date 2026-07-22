class Solution {
public:
    const int mod=1e9+7;
    int countOrders(int n) {
        long long ans=1;
        for(int i=2*n;i>=1;i-=2)
            ans=((ans*i*(i-1))/2)%mod;
        return ans;
    }
};