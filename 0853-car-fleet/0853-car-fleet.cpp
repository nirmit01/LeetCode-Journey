class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i].first=position[i];
            vec[i].second=speed[i];
        }
        sort(vec.begin(),vec.end());
        stack<double> st;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            double pos=vec[i].first,sp=vec[i].second;
            double time = (target-pos)/sp;
            st.push(time);
        }
        while(!st.empty())
        {
            double k=st.top();
            st.pop();
            while(!st.empty() && k>=st.top())
            {
                st.pop();
            }
            cnt++;
        }
        return cnt;
    }
};