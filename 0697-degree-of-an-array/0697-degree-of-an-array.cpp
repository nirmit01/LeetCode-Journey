class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int last[50000],cnt[50000];
        memset(cnt,0,sizeof(cnt)
        
        );
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            last[nums[i]]=i;
            cnt[nums[i]]=0;
        }
        int ans=INT_MAX;
        for(int i=(int)nums.size()-1;i>=0;i--)
        {
            cnt[nums[i]]++;
            if(maxi<cnt[nums[i]])
            {
                maxi=cnt[nums[i]];
                ans=last[nums[i]]-i+1;
            }
            if(maxi==cnt[nums[i]])
            {
                ans=min(ans,last[nums[i]]-i+1);
            }
        }
        return ans;
    }
};