class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> ans;
        int n=min(k,(int)nums1.size()),m=nums2.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums1[i]+nums2[0],i,0});
        }
        int cnt=0;
        while(cnt<k)
        {
            auto x=pq.top();
            pq.pop();
            ans.push_back({nums1[x[1]],nums2[x[2]]});
            if(x[2]<m-1)
                pq.push({nums1[x[1]]+nums2[x[2]+1],x[1],x[2]+1});
            cnt++;
        }
        return ans;
    }
};