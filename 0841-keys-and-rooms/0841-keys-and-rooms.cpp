class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        deque<int> dq;
        int n=rooms.size();
        dq.push_back(0);
        int visited[n];
        memset(visited,0,sizeof(visited));
        visited[0]=1;
        int cnt=1;
        while(!dq.empty())
        {
            int k=dq.front();
            dq.pop_front();
            for(auto i:rooms[k])
            {
                if(!visited[i])
                {
                    dq.push_back(i);
                    visited[i]=1;
                    cnt++;
                }
            }
        }
        return (cnt==n);
    }
};