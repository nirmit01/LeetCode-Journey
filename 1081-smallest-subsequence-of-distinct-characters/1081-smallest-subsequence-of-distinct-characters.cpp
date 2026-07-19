class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> seen(26,-1), vis(26);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            seen[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            int k=s[i]-'a';
            if(vis[k])
                continue;
            while(!ans.empty() && k<(ans.back()-'a') && seen[ans.back()-'a']>i)
            {
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[k]=1;
        }
        return ans;
    }
};