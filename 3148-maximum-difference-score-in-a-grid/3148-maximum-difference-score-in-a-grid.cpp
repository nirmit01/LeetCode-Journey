class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=INT_MIN;
        for(int i=1;i<n;i++)
        {
            int k=grid[i][0];
            ans=max(ans, k-grid[i-1][0]);
            grid[i][0]=min(grid[i][0],grid[i-1][0]);
        }
        for(int j=1;j<m;j++)
        {
            int k=grid[0][j];
            ans=max(ans, k-grid[0][j-1]);
            grid[0][j]=min(grid[0][j],grid[0][j-1]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int k=grid[i][j];
                int mn=min(grid[i][j-1],grid[i-1][j]);
                ans=max(ans,k-mn);
                grid[i][j]=min(grid[i][j],mn);
            }
        }
        return ans;
    }
};