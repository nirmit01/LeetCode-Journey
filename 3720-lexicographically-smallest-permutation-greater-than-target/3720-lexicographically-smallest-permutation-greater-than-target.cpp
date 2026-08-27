class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26);
        for(char c:s)
            freq[c-'a']++;
        
        string ans="";
        int i=0;
        for(;i<n;i++)
        {
            if(freq[target[i]-'a']>0)
            {
                ans.push_back(target[i]);
                freq[target[i]-'a']--;
            }
            else
                break;
        }
        while(true)
        {
            if(i<n)
            {
                int k=target[i]-'a';
                for(int c=k+1;c<26;c++)
                {
                    if(freq[c]>0)
                    {
                        ans+=char('a'+c);
                        freq[c]--;
                        for(int j=0;j<26;j++)
                        {
                            ans+=string(freq[j],char('a'+j));
                        }
                        return ans;
                    }
                }
            }
            if(i==0)
                return "";
            i--;
            char c = ans.back();
            ans.pop_back();
            freq[c-'a']++;
        }
        return "";
    }
};