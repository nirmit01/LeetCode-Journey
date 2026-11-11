class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        int k=min(need1,need2);
        ans+=1LL*k*min(costBoth,cost1+cost2);
        need1-=k;
        need2-=k;
        ans+=1LL*need1*min(cost1,costBoth);
        ans+=1LL*need2*min(cost2,costBoth);
        return ans;
    }
};