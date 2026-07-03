class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& x:times)
        {
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto [d,v]=pq.top();
            pq.pop();
            if(d>dist[v])
                continue;
            for(auto [u,w] : adj[v])
            {
                if(dist[u]>dist[v]+w)
                {
                    dist[u]=dist[v]+w;
                    pq.push({dist[u],u});
                }
            }
        }
        dist[0]=-1;
        int ans= *max_element(dist.begin(),dist.end());
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};