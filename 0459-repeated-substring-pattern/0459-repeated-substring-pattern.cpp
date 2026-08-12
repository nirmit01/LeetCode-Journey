class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int> lps(n);
        int i=1,len=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else if(len>0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
        int k=n-lps[n-1];
        return lps[n-1]>0 && n%(n-lps[n-1])==0;
    }
};