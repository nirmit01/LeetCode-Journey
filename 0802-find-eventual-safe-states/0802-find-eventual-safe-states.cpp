class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i=0;i<n;i++)
        {
            indegree[i]+=graph[i].size();
            for(auto&v : graph[i])
            {
                adj[v].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            ans.push_back(k);
            for(auto& x : adj[k])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};