class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int maxi=0,j=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'A']++;
            maxi=max(maxi,freq[s[i]-'A']);
            if(((i-j+1)-maxi)<=k)
                ans=max(ans,i-j+1);
            else
            {
                while((i-j+1)-maxi>k)
                {
                    freq[s[j]-'A']--;
                    j++;
                }
            }
        }
        return ans;
    }
};