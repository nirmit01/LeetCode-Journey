class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int x=points[i][0],y=points[i][1];
            pq.push({x*x+y*y,i});
        }
        vector<vector<int>> ans;
        while(k>0)
        {
            auto z=pq.top();
            pq.pop();
            int i=z.second;
            ans.push_back({points[i][0],points[i][1]});
            k--;
        }
        return ans;
    }
};