class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        int visited[n];
        memset(visited,0,sizeof(visited));
    
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int k=q.front();
                q.pop();
                if(nums[k]==0)
                    return true;
                int a=k+nums[k],b=k-nums[k];
                if(a<n && !visited[a])
                {
                    q.push(a);
                    visited[a]=1;
                }
                if(b>=0 && !visited[b])
                {
                    q.push(b);
                    visited[b]=1;
                }
            }
        }
        return false;
    }
};