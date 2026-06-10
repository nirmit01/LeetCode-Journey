class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)
        {
            return s;
        }
        int ans=0,start=0;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<=n-1)
            {
                if(s[l]==s[r])
                {
                    if(r-l+1>ans)
                    {
                        ans=r-l+1;
                        start=l;
                    }
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            l=i,r=i+1;
            while(l>=0 && r<=n-1)
            {
                if(s[l]==s[r])
                {
                    if(r-l+1>ans)
                    {
                        ans=r-l+1;
                        start=l;
                    }
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
        }
        return s.substr(start,ans);
    }
};