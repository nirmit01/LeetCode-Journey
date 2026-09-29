class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if((n+m-1)%2 || grid[0][0]==')' || grid[n-1][m-1]=='(')
            return false;
        
        vector<vector<bitset<201>>> dp(n,vector<bitset<201>>(m));
        dp[0][0][1]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                    continue;
                bitset<201> prev;
                if(i)
                    prev|=dp[i-1][j];
                if(j)
                    prev|=dp[i][j-1];
                
                if(grid[i][j]=='(')
                    prev<<=1;
                else
                    prev>>=1;
                
                dp[i][j]=prev;
            }
        }
        return dp[n-1][m-1][0]==1;
    }
};