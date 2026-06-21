class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int maxi=1e5+1;
        vector<long long> price(maxi);
        for(int i:costs)
        {
            price[i]++;
        }
        int cnt=0,i=1;
        while(coins>0 && i<maxi)
        {
            if(price[i]>0)
            {
                long long tot=price[i]*i;
                if(tot<=coins)
                {
                    cnt+=price[i];
                    coins-=tot;
                }
                else
                {
                    cnt+=(coins)/i;
                    coins=0;
                }
            }
            i++;
        }
        return cnt;
    }
};