class Solution {
public:
    int nodes=0;
    int degree=0;

    void dfs(int i,vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[i]=1;
        nodes++;
        degree+=adj[i].size();
        for(auto j:adj[i])
        {
            if(!visited[j])
                dfs(j,adj,visited);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& x:edges)
        {
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                nodes=0;
                degree=0;
                dfs(i,adj,visited);
                if(degree==((nodes)*(nodes-1)))
                    ans++;
            }
        }
        return ans;
    }
};