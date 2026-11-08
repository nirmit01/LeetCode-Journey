class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp1,mpp2;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    mpp1[i]++;
                    mpp2[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (mpp1[i]>1 || mpp2[j]>1))
                    ans++;
            }
        }
        return ans;
    }
};
