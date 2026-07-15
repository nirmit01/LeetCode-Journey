class Solution {
public:
    const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({efficiency[i],speed[i]});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        long long ans=0,sm=0;
        for(int i=0;i<n;i++)
        {
            pq.push(vec[i].second);
            sm+=vec[i].second;
            if(pq.size()>k)
            {
                sm-=pq.top();
                pq.pop();
            }
            ans=max(ans,(sm*vec[i].first));
        }
        return ans%mod;
    }
};