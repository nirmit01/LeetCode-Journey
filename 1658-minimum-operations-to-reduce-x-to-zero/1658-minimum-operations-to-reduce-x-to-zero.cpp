class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        for(int i:nums)
            tot+=i;
        int ans=-1,n=nums.size();
        int req=tot-x;
        int curr=0,j=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            while(j<=i && curr>req)
            {
                curr-=nums[j];
                j++;
            }
            if(curr==req)
            {
                ans=max(ans,i-j+1);
            }
        }
        return (ans==-1) ? ans : n-ans;
    }
};