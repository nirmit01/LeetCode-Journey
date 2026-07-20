class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int idx=i,idy=j+k;
                if(idy>m-1)
                {
                    idx+=(idy/m);
                    idy=idy%m;
                }
                if(idx>n-1)
                {
                    idx=idx%n;
                }
                ans[idx][idy]=grid[i][j];
            }
        }
        return ans;
    }
};