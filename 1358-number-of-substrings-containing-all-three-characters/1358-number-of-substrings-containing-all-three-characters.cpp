class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0,n=s.size();
        vector<int> freq(3);
        int ans=0;
        while(right<n)
        {
            while(right<n && (freq[0]<1 || freq[1]<1 || freq[2]<1))
            {
                freq[s[right]-'a']++;
                right++;
            }
            while(left<n && (freq[0]>=1 && freq[1]>=1 && freq[2]>=1))
            {
                ans+=(n-right+1);
                freq[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};