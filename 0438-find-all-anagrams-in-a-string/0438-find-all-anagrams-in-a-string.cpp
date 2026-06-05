class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq1(26),freq2(26);
        int n=p.size(),m=s.size();
        for(int i=0;i<n;i++)
            freq1[p[i]-'a']++;
        for(int i=0;i<m;i++)
        {
            freq2[s[i]-'a']++;
            if(i>=n)
                freq2[s[i-n]-'a']--;
            if(freq1==freq2)
                ans.push_back(i-n+1);
        }
        return ans;
    }
};