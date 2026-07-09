class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        int id=0;
        for(int i=1;i<n;i++)
        {
            if((nums[i]-nums[i-1])>maxDiff)
            {
                id++;
            }
            group[i]=id; 
        }
        vector<bool> ans;
        for(auto& v:queries)
        {
            ans.push_back(group[v[0]]==group[v[1]]);
        }
        return ans;
    }
};