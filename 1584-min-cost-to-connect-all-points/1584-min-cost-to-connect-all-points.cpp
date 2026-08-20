class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        vector<int> dist(n,INT_MAX), vis(n);
        dist[0]=0;
        for(int i=0;i<n;i++)
        {
            int u=-1;
            for(int j=0;j<n;j++)
            {
                if(!vis[j] && (u==-1 || dist[j]<dist[u]))
                    u=j;
            }
            vis[u]=true;
            ans+=dist[u];
            for(int j=0;j<n;j++)
            {
                if(!vis[j])
                {
                    int k= abs(points[u][0]-points[j][0])+abs(points[u][1]-points[j][1]);
                    dist[j]=min(dist[j],k);
                }
            }
        }
        return ans;
    }
};