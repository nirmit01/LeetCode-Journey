class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        int k=edges.size();
        for(int i=0;i<k;i++)
        {
            int u=edges[i][0],v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        vector<double> prob(n);
        prob[start_node]=1;
        while(!pq.empty())
        {
            auto [wt,node]=pq.top();
            pq.pop();
            if(wt<prob[node])
                continue;
            if(node==end_node)
                return wt;
            for(auto& [u,x]:adj[node])
            {
                if(wt*x>prob[u])
                {
                    prob[u]=wt*x;
                    pq.push({wt*x,u});
                }
            }
        }
        return prob[end_node];
    }
};