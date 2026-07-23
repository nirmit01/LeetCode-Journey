class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.resize(n);
        for(auto& v:edges)
            adj[v[0]].push_back({v[1],v[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n,INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty())
        {
            auto [d,u]=pq.top();
            pq.pop();
            if(dist[u]<d)
                continue;
            if(u==node2)
                return dist[u];
            for(auto& [v,wt]:adj[u])
            {
                if(dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[node2]==INT_MAX)
            return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */