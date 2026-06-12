class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int> st1,st2;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st1.push(i);
            else if(s[i]=='*')
                st2.push(i);
            else
            {
                if(!st1.empty())
                    st1.pop();
                else if(!st2.empty())
                    st2.pop();
                else
                    return false;
            }
        }
        while(!st1.empty() && !st2.empty() && st1.top()<st2.top())
        {
            st1.pop();
            st2.pop();
        }
        if(!st1.empty())
            return false;
        return true;
    }
};