class Solution {
public:

    bool dfs(int idx, vector<vector<int>>& graph,vector<int>& color)
    {
        queue<int> q;
        q.push(idx);
        color[idx]=1;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            int col=color[k];
            for(auto x: graph[k])
            {
                if(color[x]==0)
                {
                    color[x]=-col;
                    q.push(x);
                }
                else
                {
                    if(color[x]==col)
                        return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n);
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                if(!dfs(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};