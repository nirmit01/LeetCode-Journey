class Solution {
public:
    vector<int> dp;
    bool solve(int mask, int rem,int n)
    {
        if(dp[mask]!=-1)
            return dp[mask];
        
        for(int i=1;i<=n;i++)
        {
            if(mask & 1<<(i-1))
                continue;
            
            if(i>=rem)
                return dp[mask]=true;
            
            int newmask= mask | 1<<(i-1);
            if(!solve(newmask,rem-i,n))
                return dp[mask]=true;
        }
        return dp[mask]=false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        dp=vector<int>(1<<20,-1);
        int tot= (maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(desiredTotal<=maxChoosableInteger)
            return true;
        if(desiredTotal>tot)
            return false;
        
        return solve(0,desiredTotal,maxChoosableInteger);
    }
};