class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=grid[i][j];
                int mn=INT_MAX;
                if(i>0){
                    mn=min(mn,grid[i-1][j]);
                }
                if(j>0){
                    mn=min(mn,grid[i][j-1]);
                }
                if(mn!=INT_MAX){
                    ans=max(ans,curr-mn);
                    grid[i][j]=min(mn,curr);
                }
            }
        }
        return ans;
    }
};