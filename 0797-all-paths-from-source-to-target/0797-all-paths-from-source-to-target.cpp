class Solution {
public:
    int target;
    void dfs(int node,vector<int>temp, vector<vector<int>>& adj,vector<vector<int>>& ans)
    {
        if(node==target)
        {
            ans.push_back(temp);
            return;
        }
        for(int x:adj[node])
        {
            if(find(temp.begin(),temp.end(),x)==temp.end())
            {
                temp.push_back(x);
                dfs(x,temp,adj,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size();
        target=n-1;
        temp.push_back(0);
        dfs(0,temp,graph,ans);
        return ans;
    }
};