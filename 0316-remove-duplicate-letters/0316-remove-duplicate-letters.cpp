class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26,-1),visited(26);
        for(int i=0;i<s.size();i++)
        {
            seen[s[i]-'a']=i;
        }
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(visited[s[i]-'a'])
                continue;
            while(!ans.empty() && ans.back()>s[i] && seen[ans.back()-'a']>i)
            {
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[ans.back()-'a']=1;
        }
        return ans;
    }
};