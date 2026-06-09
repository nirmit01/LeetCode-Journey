class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        stack<char> st;
        int n=s.size();
        while(i<n)
        {
            if(st.empty() || st.top()!=s[i])
                st.push(s[i]);
            else
                st.pop();
            i++;
            
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