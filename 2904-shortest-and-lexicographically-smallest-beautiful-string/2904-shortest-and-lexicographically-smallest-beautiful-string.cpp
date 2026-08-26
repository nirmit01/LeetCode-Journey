class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size(), l=0;
        string curr="";
        int ones=0;
        int ans=INT_MAX;
        for(int r=0;r<n;r++)
        {
            if(s[r]=='1')
                ones++;
            
            while(ones>k)
            {
                if(s[l]=='1')
                    ones--;
                l++;
            }

            if(ones==k)
            {
                while(l<=r && s[l]=='0')
                    l++;
                
                int len=r-l+1;
                if(len<ans)
                {
                    ans=len;
                    curr=s.substr(l,len);
                }
                else if(len==ans)
                {
                    string temp=s.substr(l,len);
                    if(temp<curr)
                        curr=temp;
                }
            }
        }
        return curr;
    }
};