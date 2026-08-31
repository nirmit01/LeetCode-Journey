class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n=expression.size();
        for(int i=0;i<n;i++)
        {
            if(expression[i]==',')
                continue;
            else if(expression[i]!=')')
                st.push(expression[i]);
            else
            {
                vector<bool> v;
                while(st.top()!='(')
                {
                    char k=st.top();
                    if(k=='t')
                        v.push_back(true);
                    else
                        v.push_back(false);
                    st.pop();
                }
                st.pop();
                char c=st.top();
                st.pop();
                bool ans=v[0];
                if(c=='&')
                {
                    for(bool x:v)
                        ans = ans && x;
                }
                else if(c=='|')
                {
                    for(bool x:v)
                        ans = ans || x;
                }
                else if(c=='!')
                {
                    ans = !ans;
                }
                if(ans)
                    st.push('t');
                else
                    st.push('f');
            }
        }
        return st.top()=='t' ? true : false;
    }
};