class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int p0=0,p1=0;
        int n=s.size();
        for(char c:t)
        {
            if(p1<n && s[p1]==c)
                p1++;

            p1=max(p1,p0+1);
            
            if(p0<n && s[p0]==c)
                p0++;
        }
        return (p1==n || p0==n);
    }
};