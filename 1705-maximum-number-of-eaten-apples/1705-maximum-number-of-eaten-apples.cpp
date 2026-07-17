class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int n=apples.size();
        int cnt=0, i=0;
        while(i<n || !pq.empty())
        {
            if(i<n && apples[i]!=0)
                pq.push({i+days[i],apples[i]});

            while(!pq.empty() && pq.top().first<=i)
                pq.pop();

            if(!pq.empty())
            {
                auto k=pq.top();
                pq.pop();
                cnt++;
                k.second--;
                if(k.second>0 && k.first>i+1)
                    pq.push({k.first,k.second});
            }
            i++;
        }
        return cnt;
    }
};