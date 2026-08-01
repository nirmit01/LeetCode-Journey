class Solution {
public:
    unordered_map<int,bool> mpp;
    bool solve(int mask, int rem,int n)
    {
        if(mpp.count(mask))
            return mpp[mask];
        
        for(int i=1;i<=n;i++)
        {
            if(mask & 1<<(i-1))
                continue;
            
            if(i>=rem)
                return mpp[mask]=true;
            
            int newmask= mask | 1<<(i-1);
            if(!solve(newmask,rem-i,n))
                return mpp[mask]=true;
        }
        return mpp[mask]=false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int tot= (maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(desiredTotal<=maxChoosableInteger)
            return true;
        if(desiredTotal>tot)
            return false;
        
        return solve(0,desiredTotal,maxChoosableInteger);
    }
};