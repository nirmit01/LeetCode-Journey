class Solution {
public:

    bool dfs(int i, vector<int>& state, vector<vector<int>>& graph)
    {
        if(state[i]==2) return true;
        if(state[i]==1) return false;

        state[i]=1;
        for(auto& x: graph[i])
        {
            if(!dfs(x,state,graph))
            {
                return false;
            }
        }
        state[i]=2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> state(n),ans;
        for(int i=0;i<n;i++)
        {
            if(dfs(i,state,graph))
                ans.push_back(i);
        }
        return ans;
    }
};