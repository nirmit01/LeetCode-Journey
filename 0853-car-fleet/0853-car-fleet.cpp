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
        sort(vec.rbegin(),vec.rend());
        int cnt=0;
        double maxi=0.0;
        for(auto& [pos,sp] : vec)
        {
            double time = (double)(target-pos)/sp;
            if(time>maxi)
            {
                cnt++;
                maxi=time;
            }
        }   
        return cnt;
    }
};