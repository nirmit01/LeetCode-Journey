class Solution {
public:
    int solve(vector<int>& v1, vector<int>& d1, vector<int>& v2, vector<int>& d2)
    {
        int n=v1.size(),m=v2.size();
        int mini=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,v1[i]+d1[i]);
        }
        for(int j=0;j<m;j++)
        {
            ans=min(ans,max(mini,v2[j])+d2[j]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1=solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int ans2=solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(ans1,ans2);
    }
};