class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back({nums[i],i});
        sort(vec.begin(),vec.end());
        vector<int> ans(n);
        int i=0;
        while(i<n)
        {
            int end=i;
            vector<int> indices;
            while(end<n-1 && (vec[end+1].first-vec[end].first)<=limit)
            {
                indices.push_back(vec[end].second);
                end++;
            }
            indices.push_back(vec[end].second);

            sort(indices.begin(),indices.end());
            int sz=indices.size();
            for(int j=0;j<sz;j++)
            {
                ans[indices[j]]=vec[i+j].first;
            }
            i=end+1;
        }   
        return ans;
    }
};