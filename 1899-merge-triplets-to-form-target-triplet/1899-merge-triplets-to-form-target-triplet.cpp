class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3);
        for(auto& v:triplets)
        {
            if(target[0]>=v[0] && target[1]>=v[1] && target[2]>=v[2])
            {
                ans[0]=max(ans[0],v[0]);
                ans[1]=max(ans[1],v[1]);
                ans[2]=max(ans[2],v[2]);
            }
        }
        return (ans==target);
    }
};