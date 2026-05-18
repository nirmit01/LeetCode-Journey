class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]].push_back(i);
        }
        vector<int> visited(n);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int i=q.front();
                q.pop();
                if(i==n-1)
                    return steps;
                if(i+1<n && !visited[i+1])
                {
                    q.push(i+1);
                    visited[i+1]=1;
                }
                if(i-1>=0 && !visited[i-1])
                {
                    q.push(i-1);
                    visited[i-1]=1;
                }
                for(int k:mpp[arr[i]])
                {
                    if(!visited[k])
                    {
                        q.push(k);
                        visited[k]=1;
                    }
                }
                mpp[arr[i]].clear();
            }
            steps++;
        }
        return steps;
    }
};