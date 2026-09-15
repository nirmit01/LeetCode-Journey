class Solution {
public:
    bool issafe(int i,int j,vector<string>& board)
    {
        for(int k=0;k<i;k++)
        {
            if(board[k][j]=='Q')
                return false;
        }
        int n=board.size();
        int idx=i-1,idy=j-1;
        while(idx>=0 && idy>=0)
        {
            if(board[idx][idy]=='Q')
                return false;
            idx--;
            idy--;
        }
        idx=i-1,idy=j+1;
        while(idx>=0 && idy<n)
        {
            if(board[idx][idy]=='Q')
                return false;
            idx--;
            idy++;
        }
        return true;
    }
    void solve(int x,vector<string>& board,vector<vector<string>>& ans)
    {
        int n=board.size();
        if(x==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(x,i,board))
            {
                board[x][i]='Q';
                solve(x+1,board,ans);
                board[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,board,ans);
        return ans;
    }
};