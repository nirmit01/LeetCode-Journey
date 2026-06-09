class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& e:edges)
        {
            int u=e[0],v=e[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<vector<int>> dp(n,vector<int>(26));
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dp[i][colors[i]-'a']++;
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            cnt++;
            for(auto i:adj[k])
            {
                for(int c=0;c<26;c++)
                {
                    dp[i][c]=max(dp[i][c],dp[k][c]+(c==colors[i]-'a'));
                }
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(cnt!=n)
            return -1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};