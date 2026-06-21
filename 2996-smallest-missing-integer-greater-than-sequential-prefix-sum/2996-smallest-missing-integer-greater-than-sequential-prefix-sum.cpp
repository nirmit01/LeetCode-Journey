class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int tot=nums[0],n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                tot+=nums[i];
            else
                break;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.count(tot))
            tot++;
        return tot;
    }
};