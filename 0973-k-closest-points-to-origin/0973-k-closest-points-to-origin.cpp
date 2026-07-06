class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,int>> pq;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int x=points[i][0],y=points[i][1];
            int val=x*x+y*y;
            while(pq.size()>k)
                pq.pop();
            if(pq.size()<k)
                pq.push({val,i});
            else if(pq.top().first>val)
            {
                pq.pop();
                pq.push({val,i});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto z=pq.top();
            pq.pop();
            int i=z.second;
            ans.push_back({points[i][0],points[i][1]});
        }
        return ans;
    }
};