class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int eve=1, odd=0;
        int n=arr.size(), ans=0, pref=0;
        for(int i=0;i<n;i++){
            pref+=arr[i];
            if(pref%2){
                ans=(ans+eve)%mod;
                odd++;
            }
            else{
                ans=(ans+odd)%mod;
                eve++;    
            }
        }
        return ans;
    }
};