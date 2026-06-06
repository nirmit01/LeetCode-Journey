class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto&x:prerequisites)
        {
            int u=x[1];
            int v=x[0];
            adj[u].push_back(v);
            indegree[v]++;
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
            for(int&x:adj[k])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        if(ans.size()==n)
            return ans;
        return {};   
    }
};