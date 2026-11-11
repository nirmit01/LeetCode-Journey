class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if((long long)cost1+cost2>=costBoth)
        {
            int k=min(need1,need2);
            ans+=(long long)k*costBoth;
            need1-=k;
            need2-=k;
        }
        if(cost1>costBoth)
            ans+=(long long)need1*costBoth;
        else
            ans+=(long long)need1*cost1;
        need1=0;
        
        if(cost2>costBoth)
            ans+=(long long)need2*costBoth;
        else
            ans+=(long long)need2*cost2;
        need2=0;
        return ans;
    }
};