class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long tot=k1+k2;
        int n=nums1.size();
        vector<long long> vec(100000+2);
        for(int i=0;i<n;i++)
        {
            vec[abs(nums1[i]-nums2[i])]++;
        }
        for(int d=100000;d>0;d--)
        {
            if(vec[d]==0)
                continue;
            int take=min(1LL*vec[d],tot);
            vec[d]-=take;
            vec[d-1]+=take;
            tot-=take;
            if(tot==0)
                break;
        }
        long long ans=0;
        for(int i=1;i<=100000;i++)
            ans=ans+vec[i]*i*i;
        return ans;
    }
};