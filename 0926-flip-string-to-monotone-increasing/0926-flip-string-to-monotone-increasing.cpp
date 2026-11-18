class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                cnt0++;
        }
        int c0=0,c1=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int req=c1+(cnt0-c0);
            if(s[i]=='0')   req--;
            ans=min(ans,req);
            if(s[i]=='1')   c1++;
            else c0++;
        }
        return ans;
    }
};