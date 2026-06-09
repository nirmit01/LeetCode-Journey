class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto&x: relations)
        {
            int u=x[0]-1,v=x[1]-1;
            adj[u].push_back(v);
            degree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0)
                q.push(i);
        }
        vector<int> dp=time;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(auto i:adj[k])
            {
                dp[i]=max(dp[i],dp[k]+time[i]);
                degree[i]--;
                if(degree[i]==0)
                    q.push(i);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};