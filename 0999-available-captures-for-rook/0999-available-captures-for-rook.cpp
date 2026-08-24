class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y,n=8;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]=='R')
                {
                    x=i;
                    y=j;
                }
            }
        }
        int ans=0;
        int i1=x-1,i2=x+1;
        int j1=y-1,j2=y+1;
        while(i1>=0)
        {
            if(board[i1][y]=='p')
            {
                ans++;
                break;
            }
            else if(board[i1][y]=='B')
                break;
            else
                i1--;
        }
        while(i2<n)
        {
            if(board[i2][y]=='p')
            {
                ans++;
                break;
            }
            else if(board[i2][y]=='B')
                break;
            else
                i2++;
        }
        while(j2<n)
        {
            if(board[x][j2]=='p')
            {
                ans++;
                break;
            }
            else if(board[x][j2]=='B')
                break;
            else
                j2++;
        }
        while(j1>=0)
        {
            if(board[x][j1]=='p')
            {
                ans++;
                break;
            }
            else if(board[x][j1]=='B')
                break;
            else
                j1--;
        }
        return ans;
    }
};