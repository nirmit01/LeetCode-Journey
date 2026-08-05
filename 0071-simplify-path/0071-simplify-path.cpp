class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i=0,n=path.size();
        while(i<n)
        {
            while(i<n && path[i]=='/')
                i++;
            
            if(i==n)
                break;
            string curr;
            while(i<n && path[i]!='/')
                curr+=path[i++];

            if(curr==".")
                continue;
            else if(curr=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(curr);
        }
        string ans;
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.empty())
            return "/";
        return ans;
    }
};