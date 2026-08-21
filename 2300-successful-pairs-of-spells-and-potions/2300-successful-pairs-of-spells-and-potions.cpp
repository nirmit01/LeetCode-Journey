class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> suff(100000+1);
        int maxi=0;
        for(int i:potions)
        {
            suff[i]++;
            maxi=max(i,maxi);
        }
        for(int i=maxi-1;i>=0;i--)
            suff[i]+=suff[i+1];
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            long long req=(success+spells[i]-1)/spells[i];
            if(req<=maxi)
                ans[i]=suff[req];
            else
                ans[i]=0;
        }
        return ans;
    }
};