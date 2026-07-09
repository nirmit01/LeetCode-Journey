class Solution {
public:
    vector<int> parent,size;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b)
    {
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
            return;
        if(size[pa]<size[pb])
            swap(pa,pb);
        parent[pb]=pa;
        size[pa]+=size[pb];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        for(auto&v :edges)
        {
            if(find(v[0])==find(v[1]))
                return {v[0],v[1]};
            unite(v[0],v[1]);
        }
        return {-1,-1};
    }
};