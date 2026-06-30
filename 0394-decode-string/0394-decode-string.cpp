class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;
        int num=0;
        string curr="";
        for(char c:s)
        {
            if(isdigit(c))
            {
                num=num*10+(c-'0');
            }
            else if(c=='[')
            {
                st1.push(num);
                st2.push(curr);
                num=0;
                curr="";
            }
            else if(c==']')
            {
                int k=st1.top();
                st1.pop();
                string prev=st2.top();
                st2.pop();
                string temp;
                while(k--)
                {
                    temp+=curr;
                }
                curr=prev+temp;
            }
            else
            {
                curr+=c;
            }
        }
        return curr;
    }
};