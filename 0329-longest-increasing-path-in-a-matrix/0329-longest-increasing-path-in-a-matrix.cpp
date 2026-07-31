class Solution {
public:

    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=1;
        int dirs[]={0,1,0,-1,0};
        int n=matrix.size(),m=matrix[0].size();
        for(int k=0;k<4;k++)
        {
            int ni=i+dirs[k],nj=j+dirs[k+1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j])
            {
                dp[i][j]=max(dp[i][j],1+dfs(ni,nj,matrix,dp));
            }
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};