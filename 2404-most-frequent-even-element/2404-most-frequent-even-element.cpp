class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size(),maxi=0;
        bool flag=false;
        unordered_map<int,int> mpp;
        for(int i:nums)
        {
            if(i%2==0)
            {
                mpp[i]++;
                flag=true;
                maxi=max(maxi,mpp[i]);
            }
        }
        if(!flag)
            return -1;
        int ans=INT_MAX;
        for(auto k:mpp)
        {
            if(k.second==maxi)
                ans=min(ans,k.first);
        }
        return ans;
    }
};