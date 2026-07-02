class Solution {
public:
    const int inf=INT_MAX;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        deque<pair<int,int>> q;
        q.push_front({0,0});
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,inf));
        dist[0][0]=grid[0][0];
        int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop_front();
            for(auto &d: dirs)
            {
                int nx=x+d[0],ny=y+d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && (dist[x][y]+grid[nx][ny]<dist[nx][ny]))
                {
                    dist[nx][ny]=dist[x][y]+grid[nx][ny];
                    if(grid[nx][ny]==0)
                        q.push_front({nx,ny});
                    else
                        q.push_back({nx,ny});
                }
            }
        }
        if(dist[m-1][n-1]<health)
            return true;
        else
            return false;
    }
};