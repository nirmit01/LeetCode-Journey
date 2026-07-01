class Solution {
public:

    bool valid(vector<vector<int>>& dist,int mid, int dirs[4][2])
    {
        if(dist[0][0]<mid)
            return false;
        queue<pair<int,int>> q;
        q.push({0,0});
        int n=dist.size();
        vector<vector<int>> vis(n,vector<int>(n));
        vis[0][0]=1;
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            int x=k.first,y=k.second;
            for(int i=0;i<4;i++)
            {
                int idx=x+dirs[i][0], idy=y+dirs[i][1];
                if(idx>=0 && idx<n && idy>=0 && idy<n && !vis[idx][idy] && dist[idx][idy]>=mid)
                {
                    if(idx==n-1 && idy==n-1)
                        return true;
                    q.push({idx,idy});
                    vis[idx][idy]=1;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)
            return 0;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return 0;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int low=0,high=0;
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            int x=k.first,y=k.second;
            for(int i=0;i<4;i++)
            {
                int idx=x+dirs[i][0], idy=y+dirs[i][1];
                if(idx>=0 && idx<n && idy>=0 && idy<n && dist[idx][idy]==-1)
                {
                    dist[idx][idy]=dist[x][y]+1;
                    q.push({idx,idy});
                }
            }
        }
        high=min(dist[0][0],dist[n-1][n-1]);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(dist,mid,dirs))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;

    }
};