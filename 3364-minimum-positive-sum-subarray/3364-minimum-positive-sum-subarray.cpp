class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int s=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int curr=0;
            for(int j=i;j<min(n,i+r);j++)
            {
                curr+=nums[j];
                if(curr>0 && j-i+1>=l)
                {
                    s=min(s,curr);
                }
            }
        }
        if(s==INT_MAX)
            return -1;
        return s;
    }
};