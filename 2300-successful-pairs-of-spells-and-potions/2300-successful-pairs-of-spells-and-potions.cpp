class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            long long req=(success+spells[i]-1)/spells[i];
            int idx=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            ans[i]=m-idx;
        }
        return ans;
    }
};