class Solution {
public:
    int maxPower(string s) {
        int i=1,n=s.size(),ans=1;
        while(i<n)
        {
            int curr=1;
            while(i<n && s[i]==s[i-1])
            {
                curr++;
                i++;
            }
            ans=max(ans,curr);
            curr=1;
            i++;
        }
        return ans;
    }
};