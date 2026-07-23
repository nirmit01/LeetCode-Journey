class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vec;
        int n=scores.size();
        for(int i=0;i<n;i++)
            vec.push_back({ages[i],scores[i]});
        sort(vec.begin(),vec.end());
        int ans=0;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i]=vec[i].second;
            for(int j=0;j<i;j++)
            {
                if(vec[j].second<=vec[i].second)
                    dp[i]=max(dp[i],dp[j]+vec[i].second);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};