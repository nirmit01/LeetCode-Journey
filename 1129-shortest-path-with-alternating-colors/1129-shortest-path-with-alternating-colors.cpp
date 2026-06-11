class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n),blue(n);
        for(auto& x: redEdges)
            red[x[0]].push_back(x[1]);
        for(auto& x: blueEdges)
            blue[x[0]].push_back(x[1]);
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        queue<pair<int,int>> q;
        dist[0][0]=dist[0][1]=0;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            int val=k.first,col=k.second;
            if(col==0)
            {
                for(int x:blue[val])
                {
                    if(dist[x][1]==INT_MAX)
                    {
                        dist[x][1]=dist[val][0]+1;
                        q.push({x,1});
                    }
                }
            }
            else
            {
                for(int x:red[val])
                {
                    if(dist[x][0]==INT_MAX)
                    {
                        dist[x][0]=dist[val][1]+1;
                        q.push({x,0});
                    }
                }
            }
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int k=min(dist[i][1],dist[i][0]);
            if(k!=INT_MAX)
                ans[i]=k;
        }
        return ans;
    }
};