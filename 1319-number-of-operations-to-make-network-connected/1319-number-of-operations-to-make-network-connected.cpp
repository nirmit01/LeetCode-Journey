class Solution {
public:
    vector<int> parent,size;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int x,int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
            return;
        if(size[px]<size[py])
            swap(px,py);
        parent[py]=px;
        size[px]+=size[py];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1)
            return -1;
        parent=vector<int>(n);
        size=vector<int>(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(auto& v:connections)
            unite(v[0],v[1]);
        int ans=-1;
        for(int i=0;i<n;i++)
            if(parent[i]==i)
                ans++;
        return ans;
    }
};