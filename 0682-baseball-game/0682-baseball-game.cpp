class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string s:operations)
        {
            if(s=="+")
            {
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.push(x1);
                st.push(x1+x2);
            }
            else if(s=="C")
                st.pop();
            else if(s=="D")
                st.push(st.top()*2);
            else
                st.push(stoi(s));
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};