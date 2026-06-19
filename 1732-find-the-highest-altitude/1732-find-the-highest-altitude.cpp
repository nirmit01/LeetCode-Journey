class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0,ans=0;
        for(int i:gain)
        {
            curr+=i;
            ans=max(ans,curr);
        }
        return ans;
    }
};