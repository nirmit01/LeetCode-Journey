class Solution {
public:
    bool dfs(int i,int j,int k,vector<vector<char>>& board, string& word,int n,int m)
    {
        if(i>=n || i<0 || j>=m || j<0)
            return false;
        if(board[i][j]!=word[k])
            return false;
        k++;
        if(k==word.size())
            return true;

        char temp= board[i][j];
        board[i][j]='#';

        bool check= dfs(i+1,j,k,board,word,n,m) || dfs(i,j+1,k,board,word,n,m) || dfs(i-1,j,k,board,word,n,m) || dfs(i,j-1,k,board,word,n,m);
        
        board[i][j]=temp;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,0,board, word,n,m))
                    return true;
            }
        }
        return false;
    }
};