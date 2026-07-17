class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(),tasks.end());
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        long long t=0;
        int i=0;
        
        while(i<n || !pq.empty())
        {
            if(pq.empty() && t<tasks[i][0])
                t=tasks[i][0];
            
            while(i<n && tasks[i][0]<=t)
            {
                pq.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }
            auto k=pq.top();
            pq.pop();
            ans.push_back(k.second);
            t+=k.first;
        }
        return ans;
    }
};