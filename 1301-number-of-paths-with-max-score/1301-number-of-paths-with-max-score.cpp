class Solution {
public:
    const int inf=INT_MIN;
    const int mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> dp(n,vector<int>(m,inf)), cnt(n,vector<int>(m));
        dp[0][0]=0;
        cnt[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X')
                    continue;
                if(i==0 && j==0)
                    continue;
                int left=inf,top=inf,diag=inf;
                if(i>0) top=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                if(i>0 && j>0)  diag=dp[i-1][j-1];
                int bst=max(left,max(top,diag));
                if(bst==inf)
                    continue;
                dp[i][j]=bst;
                if(board[i][j]!='S')
                    dp[i][j]+=(board[i][j]-'0');
                if(i>0 && bst==top) cnt[i][j]=(cnt[i][j]+cnt[i-1][j])%mod;
                if(j>0 && bst==left)    cnt[i][j]=(cnt[i][j]+cnt[i][j-1])%mod;
                if(i>0 && j>0 && bst==diag) cnt[i][j]=(cnt[i][j]+cnt[i-1][j-1])%mod; 
            }
        }
        if(dp[n-1][m-1]==inf)
            return{0,0};
        return {dp[n-1][m-1],cnt[n-1][m-1]};
    }
};