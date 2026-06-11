class Solution {
public:
    void dfs(int node,int target,vector<int>temp, vector<vector<int>>& adj,vector<vector<int>>& ans,vector<int> vis)
    {
        if(target==node)
        {
            temp.push_back(target);
            ans.push_back(temp);
        }
        vis[node]=1;
        temp.push_back(node);
        for(int x:adj[node])
        {
            dfs(x,target,temp,adj,ans,vis);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size();
        vector<int> vis(n);
        dfs(0,n-1,temp,graph,ans,vis);
        return ans;
    }
};