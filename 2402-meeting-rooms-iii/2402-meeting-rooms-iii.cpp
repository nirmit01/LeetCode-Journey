class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> ava;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> bsy;
        for(int i=0;i<n;i++)
            ava.push(i);
        vector<int> cnt(n);
        for(auto& m:meetings)
        {
            long long start=m[0],end=m[1];
            long long dur=end-start;
            while(!bsy.empty() && start>=bsy.top().first)
            {
                ava.push(bsy.top().second);
                bsy.pop();
            }
            if(ava.empty())
            {
                auto b=bsy.top();
                start=b.first;
                bsy.pop();
                bsy.push({start+dur,b.second});
                cnt[b.second]++;
            }
            else
            {
                int b=ava.top();
                ava.pop();
                bsy.push({end,b});
                cnt[b]++;
            }
        }
        int maxi=0,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(cnt[i]>=maxi)
            {
                maxi=cnt[i];
                ans=i;
            }
        }
        return ans;
    }
};