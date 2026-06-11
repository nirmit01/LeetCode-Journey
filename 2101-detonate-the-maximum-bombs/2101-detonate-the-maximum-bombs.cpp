class Solution {
public:
    int dfs(int node,vector<int>& vis,vector<vector<int>>& adj)
    {
        int cnt=1;
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                cnt+=dfs(x,vis,adj);
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=(r1*r1))
                    adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n);
            ans=max(ans,dfs(i,vis,adj));
        }
        return ans;
    }
};