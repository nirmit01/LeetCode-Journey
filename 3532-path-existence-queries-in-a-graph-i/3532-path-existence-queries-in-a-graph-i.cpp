class Solution {
public:

    int find(int x,vector<int>& parent)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x],parent);
    }

    void merge(int x, int y,vector<int>& parent, vector<int>& size)
    {
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py)
            return;
        if(size[px]>size[py])
            swap(px,py);
        parent[py]=px;
        size[px]+=size[py];
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n),size(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=1;i<n;i++)
        {
            if(abs(nums[i]-nums[i-1])<=maxDiff)
                merge(i,i-1,parent,size);
        }

        vector<bool> ans;
        for(auto& v:queries)
        {
            ans.push_back(find(v[0],parent)==find(v[1],parent));
        }
        return ans;
    }
};