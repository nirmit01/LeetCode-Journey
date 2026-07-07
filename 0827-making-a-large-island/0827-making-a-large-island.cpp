class Solution {
public:
    int bfs(int id,int i,int j,vector<vector<int>>& grid)
    {
        int n=grid.size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int cnt=1;
        grid[i][j]=id;
        int dirs[5]={0,1,0,-1,0};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int idx=x+dirs[i],idy=y+dirs[i+1];
                if(idx>=0 && idx<n && idy>=0 && idy<n && grid[idx][idy]==1)
                {
                    grid[idx][idy]=id;
                    q.push({idx,idy});
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp;
        int id=2,ans=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int k=bfs(id,i,j,grid);
                    ans=max(ans,k);
                    mpp[id]=k;
                    id++;
                }
            }
        }
        int dirs[5]={0,1,0,-1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int curr=1;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++)
                    {
                        int idx=i+dirs[k],idy=j+dirs[k+1];
                        if(idx>=0 && idx<n && idy>=0 && idy<n && grid[idx][idy]!=0)
                        {
                            st.insert(grid[idx][idy]);
                        }
                    }
                    for(int i:st)
                        curr+=mpp[i];
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};