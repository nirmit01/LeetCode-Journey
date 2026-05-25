class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int>dp(n);
        int active=0;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(i-minJump>=0)
                active+=dp[i-minJump];
            
            if(i-maxJump-1>=0)
                active-=dp[i-maxJump-1];

            if(s[i]=='0' && active)
                dp[i]=1;
        }
        return dp[n-1];
    }
};