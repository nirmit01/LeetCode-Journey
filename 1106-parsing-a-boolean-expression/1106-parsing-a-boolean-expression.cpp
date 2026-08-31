class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch:expression)
        {
            if(ch==',' || ch=='('){
                continue;
            }
            else if(ch!=')'){
                st.push(ch);
            }
            else{
                bool hastrue=false, hasfalse=false;
                while(st.top()=='f' || st.top()=='t'){
                    char c=st.top();
                    st.pop();
                    if(c=='t')  hastrue=true;
                    else    hasfalse=true;
                }
                char op=st.top();
                st.pop();
                bool ans;
                if(op=='!') ans=hasfalse;
                else if(op=='&')    ans=!hasfalse;
                else    ans=hastrue;
                st.push(ans?'t':'f');
            }
        }
        return st.top()=='t';
    }
};