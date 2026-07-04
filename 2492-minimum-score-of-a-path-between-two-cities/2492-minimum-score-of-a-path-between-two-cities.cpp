class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& x:roads)
        {
            int u=x[0],v=x[1],d=x[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        int ans=INT_MAX;
        vector<int> vis(n+1);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(auto& [v,d]:adj[k])
            {
                ans=min(ans,d);
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};