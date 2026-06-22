class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        string target="123450";
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                start+=(board[i][j]+'0');
            }
        }
        vector<vector<int>> adj = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        unordered_set<string> vis;
        vis.insert(start);
        queue<string> q;
        q.push(start);
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string s=q.front();
                q.pop();
                int pos=s.find('0');
                if(s==target)
                    return ans;
                for(int i:adj[pos])
                {
                    string temp=s;
                    swap(temp[pos],temp[i]);
                    if(!vis.count(temp))
                    {
                        vis.insert(temp);
                        q.push(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};