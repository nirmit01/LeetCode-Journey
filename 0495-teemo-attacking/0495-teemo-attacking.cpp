class Solution {
public:
    int findPoisonedDuration(vector<int>& vec, int duration) {
        int ans=duration;
        int n=vec.size();
        for(int i=1;i<n;i++)
            ans+=min(duration,vec[i]-vec[i-1]);
        return ans;
    }
};