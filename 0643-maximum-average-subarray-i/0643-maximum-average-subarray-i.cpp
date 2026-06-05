class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double tot=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
            tot+=nums[i];
        double ans=tot/k;
        for(int i=k;i<n;i++)
        {
            tot+=(nums[i]-nums[i-k]);
            ans=max(ans,tot/k);
        }
        return ans;
    }
};