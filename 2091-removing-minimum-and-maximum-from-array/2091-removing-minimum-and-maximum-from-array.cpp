class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[maxi])
                maxi=i;
            if(nums[i]<nums[mini])
                mini=i;
        }
        return min(max(maxi+1,mini+1),min(max(n-maxi,n-mini),min(maxi+1+n-mini,mini+1+n-maxi)));
    }
};