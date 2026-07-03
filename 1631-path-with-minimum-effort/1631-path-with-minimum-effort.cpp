class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dirs[5]= {0,1,0,-1,0};
        priority_queue <vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            auto k=pq.top();
            pq.pop();
            int effort=k[0],x=k[1],y=k[2];
            if(dist[x][y]<effort)
                continue;
            
            for(int i=0;i<4;i++)
            {
                int idx=x+dirs[i],idy=y+dirs[i+1];
                if(idx>=0 && idx<n && idy>=0 && idy<m)
                {
                    int neweffort=max(effort, abs(heights[idx][idy]-heights[x][y]));
                    if(neweffort<dist[idx][idy])
                    {
                        dist[idx][idy]=neweffort;
                        pq.push({dist[idx][idy],idx,idy});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};