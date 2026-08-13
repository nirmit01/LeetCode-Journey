class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones)
            pq.push(i);
        
        while(pq.size()>1)
        {
            int a1=pq.top();
            pq.pop();
            int a2=pq.top();
            pq.pop();
            if(a1==a2)
                continue;
            pq.push(a1-a2);
        }
        if(pq.size())
            return pq.top();
        return 0;
    }
};