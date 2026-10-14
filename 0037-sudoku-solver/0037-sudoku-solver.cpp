class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int i,int j)
    {
        char c=board[i][j];
        for(int k=0;k<9;k++)
        {
            if(k!=j && board[i][k]==c)
                return false;
            if(k!=i && board[k][j]==c)
                return false;
        }
        for(int idx=0;idx<9;idx++)
        {
            for(int idy=0;idy<9;idy++)
            {
                int p=(i/3)*3+(idx%3);
                int q=(j/3)*3+(idy%3);
                if((p!=i || q!=j) && board[p][q]==c)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> & board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                        board[i][j]='0'+k;
                        if(isvalid(board,i,j) && solve(board))
                            return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};