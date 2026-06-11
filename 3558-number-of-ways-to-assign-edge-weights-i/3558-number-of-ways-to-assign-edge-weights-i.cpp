class Solution {
public:
    const int mod=1e9+7;
    int getpow(int x, int n)
    {
        int ans=1;
        long long a=x;
        while(n>0)
        {
            if(n&1)
            {
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            n>>=1;
        }
        return ans;
    }

    void geth(int node, int par, int h, int& ans,vector<vector<int>>& adj)
    {
        ans=max(ans,h);
        for(auto i:adj[node])
        {
            if(i==par)
                continue;
            geth(i,node,h+1,ans,adj);
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

        return getpow(2,ans-1); 
    }
};