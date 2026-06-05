class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int pref=0,ans=0;
        vector<int> mpp(2*n+1,-2);
        mpp[n]=-1;
        for(int i=0;i<n;i++)
        {
            pref+=(nums[i]) ? 1 : -1 ;
            if(mpp[pref+n]==-2)
                mpp[pref+n]=i;
            else
            {
                ans=max(ans,i-mpp[pref+n]);
            }
        }
        return ans;
    }
};