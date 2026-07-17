class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1);
        for(int i:nums)
            freq[i]++;
        
        vector<int> cnt(maxi+1);
        for(int i=1;i<=maxi;i++)
        {
            for(int j=i;j<=maxi;j+=i)
                cnt[i]+=freq[j];
        }

        vector<long long> exact(maxi+1);
        for(int i=maxi;i>0;i--)
        {
            long long tot=(1ll*cnt[i]*(cnt[i]-1))/2;
            for(int j=i*2;j<=maxi;j+=i)
            {
                tot-=exact[j];
            }
            exact[i]=tot;
        }

        vector<long long> pref(maxi+1);
        for(int i=1;i<=maxi;i++)
        {
            pref[i]=pref[i-1]+exact[i];
        }
        vector<int> ans;
        for(auto k:queries)
        {
            int g=upper_bound(pref.begin()+1,pref.end(),k)-pref.begin();
            ans.push_back(g);
        }
        return ans;
    }
};