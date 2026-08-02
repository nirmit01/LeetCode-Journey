class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector<int> mincol(61,INT_MAX);
        vector<int> maxcol(61,INT_MIN);
        vector<int> minrow(61,INT_MAX);
        vector<int> maxrow(61,INT_MIN);
        vector<bool> present(61);
        int n=targetGrid.size(),m=targetGrid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c=targetGrid[i][j];
                present[c]=true;
                mincol[c]=min(mincol[c],j);
                maxcol[c]=max(maxcol[c],j);

                minrow[c]=min(minrow[c],i);
                maxrow[c]=max(maxrow[c],i);
            }
        }
        vector<vector<int>> graph(61);
        vector<vector<bool>> edge(61,vector<bool>(61));
        for(int c=1;c<61;c++)
        {
            if(!present[c])
                continue;
            for(int i=minrow[c];i<=maxrow[c];i++)
            {
                for(int j=mincol[c];j<=maxcol[c];j++)
                {
                    int k=targetGrid[i][j];
                    if(k!=c && !edge[c][k])
                    {
                        graph[c].push_back(k);
                        edge[c][k]=true;
                    }
                }
            }
        }

        vector<int> indegree(61);
        int tot=0;
        for(int u=1;u<=60;u++)
        {
            if(present[u])
                tot++;
            for(int v:graph[u])
                indegree[v]++;
        }

        queue<int> q;
        for(int i=1;i<61;i++)
        {
            if(present[i] && indegree[i]==0)
                q.push(i);
        }

        int cnt=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            cnt++;
            for(int v:graph[k])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        return cnt==tot;
    }
};