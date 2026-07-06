class Solution {
public:
    string solve(int n)
    {
        if(n==1)
            return "1";
        string s=solve(n-1);
        string ans="";
        int i=0,sz=s.size();
        while(i<sz)
        {
            int curr=1;
            while(i<sz-1 && s[i]==s[i+1])
            {
                curr++;
                i++;
            }
            ans+=to_string(curr);
            ans+=s[i];
            i++;
        }
        return ans;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};