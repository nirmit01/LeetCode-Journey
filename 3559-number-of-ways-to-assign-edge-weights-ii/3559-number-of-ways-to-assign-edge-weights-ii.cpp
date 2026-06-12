class Solution {
public:
    const int mod=1e9+7,log=17;
    vector<int>depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    int binexp(int x,int n)
    {   
        if(n<0)
            return 0;
        int ans=1;
        long long a=x;
        while(n>0)
        {
            if(n&1)
                ans=(ans*a)%mod;
            a=(a*a)%mod;
            n>>=1;
        }
        return ans;
    }
    void dfs(int node,int par)
    {
        up[node][0]=par;
        for(int j=1;j<=log;j++)
        {
            up[node][j]=up[up[node][j-1]][j-1];
        }
        for(int i:adj[node])
        {
            if(i==par)
                continue;
            depth[i]=depth[node]+1;
            dfs(i,node);
        }
    }

    int lift(int node, int k)
    {
        for(int j=0;j<log;j++)
        {
            if(k&(1<<j))
                node=up[node][j];
        }
        return node;
    }
    int lca(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);
        u=lift(u,depth[u]-depth[v]);
        if(u==v)
            return u;
        for(int j=log;j>=0;j--)
        {
            if(up[u][j]!=up[v][j])
            {
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        adj=vector<vector<int>>(n+1);
        depth=vector<int>(n+1);
        up=vector<vector<int>>(n+1,vector<int>(log+1));
        for(auto& x:edges)
        {
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0);
        vector<int> ans;
        for(auto& q:queries)
        {
            int u=q[0],v=q[1];
            int p=lca(u,v);
            int d =depth[u]+depth[v]-2*depth[p];
            ans.push_back(binexp(2,d-1));
        }
        return ans;
    }
};