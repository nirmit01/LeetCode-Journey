class Solution {
public:
    int numDecodings(string s) {
        int cnt1=1;
        int cnt2=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;
            if(s[i]!='0')
            {
                cnt=cnt1;
                if(i<n-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6'))
                    cnt+=cnt2;
            }
            cnt2=cnt1;
            cnt1=cnt;
        }
        return cnt1;
    }
};