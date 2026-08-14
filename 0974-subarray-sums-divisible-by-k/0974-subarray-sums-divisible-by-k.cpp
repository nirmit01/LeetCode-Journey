class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int ans=0,curr=0;
        mpp[0]=1;
        for(int i:nums)
        {
            curr+=i;
            int rem=(curr%k+k)%k;
            ans+=mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }
};