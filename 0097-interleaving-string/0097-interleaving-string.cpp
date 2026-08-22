class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size();
        if(s3.size()!=n+m)
            return false;

        vector<bool> dp(m+1);
        dp[0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0)
                    continue;
                bool check1=false, check2=false;
                if(i>0 && s1[i-1]==s3[i+j-1])
                    check1=dp[j];
                if(j>0 && s2[j-1]==s3[i+j-1])
                    check2=dp[j-1];
                dp[j]=check1 || check2;
            }
        }
        return dp[m];
    }
};