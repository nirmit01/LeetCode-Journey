class Solution {
public:
    void dfs(int k, vector<vector<int>>& adj, vector<int>& vis)
    {
        if(vis[k])
            return;
        vis[k]=1;
        for(int i:adj[k])
        {
            dfs(i,adj,vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto& v:invocations)
            adj[v[0]].push_back(v[1]);
        
        vector<int> vis(n);
        dfs(k,adj,vis);
        for(auto& v:invocations)
        {
            int from=v[0],to=v[1];
            if(!vis[from] && vis[to])
            {
                vector<int> ans(n);
                iota(ans.begin(),ans.end(),0);
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(!vis[i])
                ans.push_back(i);
        return ans;


    }
};