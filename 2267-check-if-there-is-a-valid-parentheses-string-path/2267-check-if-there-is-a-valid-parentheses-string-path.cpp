class Solution {
public:

    void dfs(int i,int j,int bal, vector<vector<vector<bool>>>& vec, vector<vector<char>>& grid)
    {
        if(grid[i][j]=='(')
            bal+=1;
        else
            bal-=1;
        if(bal<0)
            return;
        
        if(vec[i][j][bal])
            return;
        vec[i][j][bal]=true;
        if(i+1<grid.size())
            dfs(i+1,j,bal,vec,grid);
        if(j+1<grid[0].size())
            dfs(i,j+1,bal,vec,grid);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if((n+m-1)%2)
            return false;
        vector<vector<vector<bool>>> vec(n,vector<vector<bool>>(m,vector<bool>(m+n)));
        dfs(0,0,0,vec,grid);
        return vec[n-1][m-1][0];
    }
};