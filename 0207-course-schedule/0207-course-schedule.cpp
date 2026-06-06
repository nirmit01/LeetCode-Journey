class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& k:prerequisites)
        {
            int u=k[1];
            int v=k[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            ++count;
            for(int i:adj[k])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        return count==n;
    }
};