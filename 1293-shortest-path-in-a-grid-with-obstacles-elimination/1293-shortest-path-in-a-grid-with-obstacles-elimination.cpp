class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        if(n==1 && m==1)
            return 0;
        if(k>=m+n-2)
            return m+n-2;
        if(grid[0][0]==1)
            k--;
        if(k<0)
            return -1;
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1)));
        queue<vector<int>> q;
        q.push({0,0,k});
        vis[0][0][k]=1;
        int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int cnt=0;
        while(!q.empty())
        {
            int sz=q.size();
            cnt++;
            while(sz--)
            {
                auto v=q.front();
                q.pop();
                int x=v[0],y=v[1];
                for(auto &d:dirs)
                {
                    int nx=x+d[0],ny=y+d[1],rem=v[2];
                    if(nx>=0 && nx<n && ny>=0 && ny<m)
                    {
                        if(grid[nx][ny]==1)
                            rem--;
                        if(nx==n-1 && ny==m-1 && rem>=0)
                            return cnt;
                        if(rem>=0 && !vis[nx][ny][rem])
                        {
                            vis[nx][ny][rem]=1;
                            q.push({nx,ny,rem});
                        }
                    }
                }
            }
        }
        return -1;
    }
};