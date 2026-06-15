class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens)
        {
            if((s[0]>=48 && s[0]<=57) || (s[0]=='-' && s.size()>1))
            {
                int num=0,k=1;
                if(s[0]=='-')
                    k=-1;
                for(char c:s)
                {
                    if(c=='-')
                        continue;
                    else
                        num=num*10+(c-'0');
                }
                st.push(k*num);
            }
            else
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if(s[0]=='/')   st.push(y/x);
                else if(s[0]=='*')  st.push(y*x);
                else if(s[0]=='+')  st.push(x+y);
                else    st.push(y-x);
            }
        }
        return st.top();
    }
};