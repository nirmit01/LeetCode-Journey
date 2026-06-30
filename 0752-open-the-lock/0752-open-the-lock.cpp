class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans=0;
        queue<string> q;
        unordered_set<string> st(deadends.begin(),deadends.end());
        if(!st.count("0000"))
        {
            q.push("0000");
            st.insert("0000");
        }
        if(!q.empty() && target==q.front())
            return ans;
        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            while(sz--)
            {
                string s=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    string temp=s;
                    temp[i]=(s[i]=='9' ? '0' : s[i]+1);
                    if(!st.count(temp))
                    {
                        if(target==temp)
                            return ans;
                        q.push(temp);
                        st.insert(temp);
                    }
                    temp=s;
                    temp[i]=(s[i]=='0' ? '9' : s[i]-1);
                    if(!st.count(temp))
                    {
                        if(target==temp)
                            return ans;
                        q.push(temp);
                        st.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
};