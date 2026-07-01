class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> mpp;
        int n=routes.size();
        for(int i=0;i<n;i++)
        {
            for(int k:routes[i])
                mpp[k].push_back(i);
        }
        vector<int> bus(n);
        unordered_set<int> stop;

        int cnt=0;
        queue<int> q;
        q.push(source);
        stop.insert(source);
        if(source==target)
            return cnt;
        while(!q.empty())
        {
            int sz=q.size();
            cnt++;
            while(sz--)
            {
                int k=q.front();
                q.pop();
                for(auto i:mpp[k])
                {
                    if(bus[i]==1)
                        continue;
                    bus[i]=1;
                    for(int z:routes[i])
                    {
                        if(z==target)
                            return cnt;
                        if(!stop.count(z))
                        {
                            stop.insert(z);
                            q.push(z);
                        }
                    }
                }
            }
        }
        return -1;
    }
};