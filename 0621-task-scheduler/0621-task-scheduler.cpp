class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<int,int>mpp;
        for(auto i:tasks)
            mpp[i]++;
        for(auto& i : mpp)
            pq.push(i.second);
        
        int time=0;
        while(!pq.empty())
        {
            int cycle=n+1;
            int i=0;
            vector<int> temp;
            while(i<cycle && !pq.empty())
            {
                int k=pq.top();
                pq.pop();
                k--;
                if(k>0)
                    temp.push_back(k);
                i++;
                time++;
            }
            for(int val:temp)
                pq.push(val);
            if(pq.empty())
                break;
            time+=cycle-i;
        }
        return time;
    }
};