class Solution {
public:

    bool check(int mid,vector<int>& topo, vector<vector<pair<int,int>>>& adj,vector<bool>& online,long long k)
    {
        int n=topo.size();
        vector<long long> dist(n,5e13+1);
        dist[0]=0;
        for(int node:topo)
        {
            for(auto [v,w]:adj[node])
            {
                if(!online[v])
                    continue;
                if(w<mid)
                    continue;
                if(dist[node]+w<dist[v])
                    dist[v]=dist[node]+w; 
            }
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);
        int low=0,high=0;
        for(auto d:edges)
        {
            int u=d[0],v=d[1],w=d[2];
            adj[u].push_back({v,w});
            indegree[v]++;
            high=max(high,w);
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto z:adj[node])
            {
                indegree[z.first]--;
                if(indegree[z.first]==0)
                    q.push(z.first);
            }
        }
        bool flag=false;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,topo,adj,online,k))
            {
                low=mid+1;
                flag=true;
            }
            else
                high=mid-1;
        }
        if(flag)
            return high;
        return -1;
    }
};