class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            gas[i]-=cost[i];
            sum+=gas[i];
        }
        if(sum<0)
            return -1;
        for(int i=1;i<n;i++)
        {
            gas[i]+=gas[i-1];
        }
        int i=min_element(gas.begin(),gas.end())-gas.begin();
        return (i+1)%n;
    }
};