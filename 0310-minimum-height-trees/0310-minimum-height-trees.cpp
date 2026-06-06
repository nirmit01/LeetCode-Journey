class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        if(n==1)
            return vector<int>{0};
        for(auto&x: edges)
        {
            int u=x[0],v=x[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        int rem=n;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
                q.push(i);
        }
        while(rem>2)
        {
            int sz=q.size();
            rem-=sz;
            while(sz--)
            {
                int k=q.front();
                q.pop();
                for(auto& x:adj[k])
                {
                    degree[x]--;
                    if(degree[x]==1)
                        q.push(x);
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};