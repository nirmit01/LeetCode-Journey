class Solution {
public:

    vector<int> compute(string& s)
    {
        int n=s.size();
        vector<int> lps(n);
        int i=1,len=0;
        while(i<n)
        {
            if(s[len]==s[i])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                    len=lps[len-1];
                else
                    i++;
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        string temp=s,z=s;
        reverse(z.begin(),z.end());
        temp=temp+"#"+z;

        vector<int> lps=compute(temp);
        int k=lps.back();

        string s2=s.substr(k);
        reverse(s2.begin(),s2.end());
        
        string ans=s2+s;
        return ans;
    }
};