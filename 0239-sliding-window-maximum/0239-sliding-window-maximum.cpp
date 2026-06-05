class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size(),maxi=INT_MIN;
        unordered_map<int,int> mpp;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]]==0)
                pq.push(nums[i]);
            mpp[nums[i]]++;
            if(i>=k)
            {
                int x=nums[i-k];
                mpp[x]--;
                while(mpp[pq.top()]==0)
                    pq.pop();
            }
            if(i>=k-1)
                ans.push_back(pq.top());
        }
        return ans;

    }
};