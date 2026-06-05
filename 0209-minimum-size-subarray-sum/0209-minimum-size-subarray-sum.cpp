class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX,curr=0;
        int i=0,j=0,n=nums.size();
        while(i<n)
        {
            curr+=nums[i];
            while(curr>=target)
            {
                ans=min(ans,i-j+1);
                curr-=nums[j];
                j++;
            }
            i++;
        }
        return (ans==INT_MAX) ? 0 : ans; 
    }
};