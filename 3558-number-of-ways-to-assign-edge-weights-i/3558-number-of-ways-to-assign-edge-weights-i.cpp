class Solution {
public:

    const int mod=1e9+7;
    int solve(int x,int n)
    {
        long long a=x;
        int ans=1;
        while(n>0)
        {
            if(n&1)
                ans=(ans*a)%mod;
            a=(a*a)%mod;
            n>>=1;
        }
        return ans;
    }

    void geth(int node, int parent, int h, int& ans, vector<vector<int>>& adj)
    {
        ans=max(ans,h);
        for(int x: adj[node])
        {
            if(x==parent)
                continue;
            geth(x,node,h+1,ans,adj);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto&x:edges)
        {
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        geth(1,0,0,ans,adj);

        return solve(2,ans-1);
    }
};