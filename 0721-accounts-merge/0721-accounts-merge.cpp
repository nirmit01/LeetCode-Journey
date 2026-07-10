class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int x, int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
            return;
        parent[px]=py;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++)
        {
            auto& v=accounts[i];
            for(int j=1;j<v.size();j++)
            {
                if(mpp.count(v[j]))
                   unite(i,mpp[v[j]]);
                else
                    mpp[v[j]]=i; 
            }
        }
        unordered_map<int,vector<string>> acc;
        for(auto& it:mpp)
        {
            int idx=find(it.second);
            acc[idx].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(auto &it:acc)
        {
            int idx=it.first;
            auto& vec=it.second;
            sort(vec.begin(),vec.end());

            vector<string> temp;
            temp.push_back(accounts[idx][0]);
            for(auto& email:vec)
                temp.push_back(email);
            
            ans.push_back(temp);
        }
        return ans;
    }
};