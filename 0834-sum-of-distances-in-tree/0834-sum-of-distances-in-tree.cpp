class Solution {
public:
    vector<int> ans, subtree;

    void dfs1(int node,int parent,int depth,vector<vector<int>>& adj)
    {
        ans[0]+=depth;
        subtree[node]=1;
        for(int v:adj[node])
        {
            if(v==parent)
                continue;
            dfs1(v,node,depth+1,adj);
            subtree[node]+=subtree[v];
        }
    }
    void dfs2(int node, int parent,vector<vector<int>>& adj,int n)
    {
        for(int child : adj[node])
        {
            if(child==parent)
                continue;
            ans[child]=ans[node]-subtree[child]+(n-subtree[child]);
            dfs2(child,node,adj,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans=vector<int>(n);
        subtree=vector<int>(n);
        vector<vector<int>> adj(n);
        for(auto& v:edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs1(0,-1,0,adj);
        dfs2(0,-1,adj,n);
        return ans;
    }
};