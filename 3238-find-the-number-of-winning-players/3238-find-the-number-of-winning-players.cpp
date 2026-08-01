class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        sort(pick.begin(),pick.end());
        int k=pick.size();
        int ans=0,i=0;
        while(i<k)
        {
            int curr=pick[i][0],col=pick[i][1];
            int cnt=0;
            while(i<k && pick[i][0]==curr && col==pick[i][1])
            {
                i++;
                cnt++;
            }
            if(cnt>curr)
            {
                ans++;
                while(i<k && pick[i][0]==curr)
                    i++;
            }
        }
        return ans;
    }
};