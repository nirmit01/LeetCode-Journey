class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool box[9][9]={false};

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int x=board[i][j]-'1';
                    int k=(i/3)*3+j/3;
                    if(row[x][i] || col[x][j] || box[x][k])
                        return false;
                    row[x][i]=true;
                    col[x][j]=true;
                    box[x][k]=true;
                }
            }
        }
        return true;
    }
};