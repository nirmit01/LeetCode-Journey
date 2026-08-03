class Solution {
public:
    int f(int i,int m,vector<int>& suffix,vector<vector<int>>& dp)
    {
        int n=suffix.size();
        if(i>=n)
            return 0;
        if((i+2*m)>=n)
            return suffix[i];
        if(dp[i][m]!=-1)
            return dp[i][m];
        
        int ans=0;
        for(int x=1;x<=2*m;x++)
        {
            ans=max(ans, suffix[i]-f(i+x,max(x,m),suffix,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> suffix(n);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]+piles[i];
        
        return f(0,1,suffix,dp);
    }
};