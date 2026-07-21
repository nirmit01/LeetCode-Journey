class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i=0,n=s.size();
        int ones=0,prev=0,ans=0;
        while(i<n)
        {
            if(i<n && s[i]=='1')
            {
                ones++;
                i++;
                continue;
            }
            int cnt=0;
            while(i<n  && s[i]=='0')
            {
                cnt++;
                i++;
            }
            if(prev>0)
            {
                ans=max(ans,prev+cnt);
            }
            prev=cnt;
        }   
        return ans+ones;
    }
};