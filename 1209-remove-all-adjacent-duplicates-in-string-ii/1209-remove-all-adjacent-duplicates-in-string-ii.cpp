class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            char c=s[i];
            int curr=0;
            while(i<n && c==s[i])
            {
                curr++;
                i++;
            }
            if(!st.empty() && st.top().first==c)
            {
                auto p=st.top();
                st.pop();
                curr+=p.second;
            }
            if(curr>=k)
            {
                if(curr%k)
                    st.push({c,curr%k});
                continue;
            }
            st.push({c,curr});
        }
        string ans="";
        while(!st.empty())
        {
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};