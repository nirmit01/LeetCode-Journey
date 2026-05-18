class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr=0,tot=0,start=0;
        for(int i=0;i<gas.size();i++)
        {
            int diff=gas[i]-cost[i];
            tot+=diff;
            curr+=diff;
            if(curr<0)
            {
                curr=0;
                start=i+1;
            }
        }
        if(tot<0)
            return -1;
        return start;
    }
};