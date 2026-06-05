class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double tot=0,ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            tot+=nums[i];
        }
        ans=max(ans,tot/k);
        int i=0,j=k;
        while(j<n)
        {
            tot+=nums[j];
            tot-=nums[i];
            j++;
            i++;
            ans=max(ans,tot/k);
        }
        return ans;
    }
};