class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++)
            nums.push_back({nums2[i],nums1[i]});
        sort(nums.begin(),nums.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0,sm=0;
        for(int i=0;i<n;i++)
        {
            if(pq.size()==k)
            {
                sm-=pq.top();
                pq.pop();
            }
            pq.push(nums[i].second);
            sm+=nums[i].second;
            if(pq.size()==k)
                ans=max(ans,sm*nums[i].first);
        }
        return ans;
    }
};