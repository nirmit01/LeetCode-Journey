class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int curr=n+1;
        long long ans=0;
        vector<long long> pref(2*n+2),tot(2*n+2);
        pref[curr]=1;
        tot[curr]=1;
        for(int i:nums)
        {
            curr+=(i==target?1:-1);
            pref[curr]++;
            tot[curr]=tot[curr-1]+pref[curr];
            ans+=tot[curr-1];
        }   
        return ans;
    }
};