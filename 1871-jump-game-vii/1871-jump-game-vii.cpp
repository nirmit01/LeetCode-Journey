class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        q.push(0);
        int far=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            int start=max(far,k+minJump);
            int end=min(k+maxJump,n-1);
            for(int i=start;i<=end;i++)
            {
                if(s[i]=='0')
                    q.push(i);
                if(s[i]=='0' && i==n-1)
                    return true;
            }
            far=end+1;
        }
        return false;
    }
};