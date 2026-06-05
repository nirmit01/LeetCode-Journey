class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26,-1),visited(26);
        for(int i=0;i<s.size();i++)
        {
            seen[s[i]-'a']=i;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(visited[s[i]-'a'])
                continue;
            while(!st.empty() && st.top()>s[i] && seen[st.top()-'a']>i)
            {
                visited[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            visited[st.top()-'a']=1;
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};