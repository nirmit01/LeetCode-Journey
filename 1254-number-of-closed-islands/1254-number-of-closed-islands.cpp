class Solution {
public:
    int n,m;
    bool dfs(vector<vector<int>>& grid, int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        
        if(grid[x][y]==1)
            return true;
        grid[x][y]=1;
        bool up=dfs(grid,x-1,y);
        bool down=dfs(grid,x+1,y);
        bool left=dfs(grid,x,y-1);
        bool right=dfs(grid,x,y+1);

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(grid,i,j))
                        ans++;
                }
            }
        }
        return ans;
    }
};