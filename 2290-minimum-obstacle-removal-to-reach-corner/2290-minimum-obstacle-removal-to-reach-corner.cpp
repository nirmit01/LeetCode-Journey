class Solution {
public:
    const int inf=INT_MAX;
    int minimumObstacles(vector<vector<int>>& grid) {
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vec(n,vector<int>(m,inf));
        vec[0][0]=grid[0][0];
        int d[5]={0,1,0,-1,0};
        while(!dq.empty())
        {
            auto [x,y]=dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++)
            {
                int nx=x+d[i],ny=y+d[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && (vec[x][y]+grid[nx][ny]<vec[nx][ny]))
                {
                    vec[nx][ny]=vec[x][y]+grid[nx][ny];
                    if(grid[nx][ny])
                        dq.push_back({nx,ny});
                    else
                        dq.push_front({nx,ny});
                }
            }
        }
        return vec[n-1][m-1];
    }
};