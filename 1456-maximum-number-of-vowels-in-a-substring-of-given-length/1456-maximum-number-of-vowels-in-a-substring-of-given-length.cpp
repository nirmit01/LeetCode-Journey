class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vol={'a','e','i','o','u'};
        int curr=0;
        for(int i=0;i<k;i++)
            if(vol.find(s[i])!=vol.end())
                curr++;
        int tot=curr,n=s.size();
        for(int i=k;i<n;i++)
        {
            if(vol.find(s[i])!=vol.end())
                curr++;
            if(vol.find(s[i-k])!=vol.end())
                curr--;
            tot=max(curr,tot);
        }
        return tot;
    }
};