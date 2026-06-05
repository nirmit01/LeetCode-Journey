class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int pref=0,ans=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
                pref+=1;
            else
                pref-=1;
            if(mpp.count(pref)==0)
                mpp[pref]=i;
            else
            {
                ans=max(ans,i-mpp[pref]);
            }
        }
        return ans;
    }
};