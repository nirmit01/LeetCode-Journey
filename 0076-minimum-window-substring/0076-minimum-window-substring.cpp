class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0;
        int n=s.size(),m=t.size();
        unordered_map<char,int> need,have;
        for(char c:t)
            need[c]++;
        
        int sz=need.size(),formed=0;
        int ans=INT_MAX;
        int i1=0,i2=0;
        while(j<n)
        {
            while(formed!=sz && j<n)
            {
                if(need.count(s[j]))
                {
                    have[s[j]]++;
                    if(have[s[j]]==need[s[j]])
                        formed++;
                }
                j++;
            }
            while(formed==sz && i<=j)
            {
                if(j-i<ans)
                {
                    ans=j-i;
                    i1=i;
                }
                if(need.count(s[i]))
                {
                    have[s[i]]--;
                    if(have[s[i]]<need[s[i]])
                        formed--;
                }
                i++;
            }
        }
        if(ans==INT_MAX)
            return "";
        return s.substr(i1,ans);
    }
};