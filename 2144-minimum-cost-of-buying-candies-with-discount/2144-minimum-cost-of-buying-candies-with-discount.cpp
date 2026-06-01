class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size(),tot=0,cnt=0;
        for(int &i:cost)
        {
            tot+=i;
        }
        if(n<3) return tot;
        for(int i=n-3;i>=0;i-=3)
        {
            cnt+=cost[i];
        }
        return tot-cnt;
    }
};