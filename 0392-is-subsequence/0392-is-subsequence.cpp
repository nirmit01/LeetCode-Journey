class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),i=0;
        for(char c:t)
        {
            if(c==s[i])
                i++;
        }
        return i==n;
    }
};