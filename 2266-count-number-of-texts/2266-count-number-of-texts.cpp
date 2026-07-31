class Solution {
public:

    const int mod=1e9+7;
    int f(int i,string& pressedKeys, vector<int>& dp)
    {
        int n=pressedKeys.size();
        if(i==n)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        long long cnt=f(i+1,pressedKeys,dp);
        int limit=3;
        if(pressedKeys[i]=='7' || pressedKeys[i]=='9')
            limit++;
        
        for(int j=1;j<limit;j++)
        {
            if(i+j>=n)
                break;
            if(pressedKeys[i+j]==pressedKeys[i])
                cnt=(cnt+f(i+j+1,pressedKeys,dp))%mod;
            else
                break;
        }
        return dp[i]=(cnt%mod);
    }

    int countTexts(string pressedKeys) {
        int n=pressedKeys.size();
        vector<int> dp(n,-1);
        return f(0,pressedKeys,dp);
    }
};