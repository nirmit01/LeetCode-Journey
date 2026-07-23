class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx=0;
        for(int i:nums)
            mx=max(mx,i);
        int k=1;
        while(k<=mx)
        {
            k<<=1;
        }
        vector<int> s(k);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                s[nums[i]^nums[j]]=1;
        }
        vector<int> cnt(k);
        for(int i=0;i<k;i++)
        {
            if(s[i]==0)
                continue;
            for(int x:nums)
                cnt[x^i]=1;
        }
        int ans=0;
        for(int x:cnt)
        {
            if(x)
                ans++;
        }
        return ans;
    }
};