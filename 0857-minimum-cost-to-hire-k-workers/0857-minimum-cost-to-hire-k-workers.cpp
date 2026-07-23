class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        vector<pair<double,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back({(double)wage[i]/(quality[i]),quality[i]});
        sort(vec.begin(),vec.end());
        priority_queue<int> pq;
        double ans=LLONG_MAX;
        long long cnt=0;
        for(auto [ratio,q]:vec)
        {
            pq.push(q);
            cnt+=q;
            if(pq.size()>k)
            {
                cnt-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=min(ans,ratio*cnt);
        }
        return ans;
    }
};