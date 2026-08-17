class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp=matrix;
        int mini1=INT_MAX,mini2=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[0][i]<mini1)
            {
                mini2=mini1;
                mini1=dp[0][i];
                ind=i;
            }
            else if(dp[0][i]<mini2)
            {
                mini2=dp[0][i];
            }
        }

        for(int i=1;i<n;i++)
        {
            int curr1=INT_MAX, curr2=INT_MAX,cind=-1;
            for(int j=0;j<n;j++)
            {
                if(j!=ind)
                    dp[i][j]+=mini1;
                else
                    dp[i][j]+=mini2;
                

                if(dp[i][j]<curr1)
                {
                    curr2=curr1;
                    curr1=dp[i][j];
                    cind=j;
                }
                else if(dp[i][j]<curr2)
                {
                    curr2=dp[i][j];
                }
            }
            mini1=curr1;
            mini2=curr2;
            ind=cind;
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};