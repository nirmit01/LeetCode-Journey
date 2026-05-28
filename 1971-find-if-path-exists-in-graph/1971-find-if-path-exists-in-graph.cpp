class Solution {
public:
    int find(int x,vector<int>& parent)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x],parent);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(auto&e:edges)
        {
            int v=e[0];
            int u=e[1];
            int parenta=find(v,parent);
            int parentb=find(u,parent);
            parent[parenta]=parent[parentb]=min(parent[parenta],parent[parentb]);
        }
        return find(source,parent)==find(destination,parent);    
    }
};