class Solution {
public:
    int ansi(vector<int>& v1, vector<int>& d1, vector<int>& v2, vector<int>& d2)
    {
        int mini=INT_MAX;
        int n=v1.size(),m=v2.size();
        for(int i=0;i<n;i++)
        {
            mini=min(mini,v1[i]+d1[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,max(mini,v2[i])+d2[i]);
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1= ansi(landStartTime, landDuration, waterStartTime, waterDuration);
        int ans2= ansi(waterStartTime, waterDuration,landStartTime, landDuration);
        return min(ans1,ans2);
    }
};