class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0,n=events.size(),j=0;
        int end=0;
        for(auto&e:events)
            end=max(end,e[1]);
        for(int day=events[0][0];day<=end;day++)
        {
            while(j<n && events[j][0]==day)
            {
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<day)
                pq.pop();
            
            if(!pq.empty() && pq.top()>=day)
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};