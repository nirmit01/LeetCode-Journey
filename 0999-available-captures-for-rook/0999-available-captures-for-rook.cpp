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
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int d=0;d<4;d++)
        {
            int i=x+dx[d];
            int j=y+dy[d];
            while(i>=0 && i<8 && j>=0 && j<8)
            {
                if(board[i][j]=='p')
                {
                    ans++;
                    break;
                }
                else if(board[i][j]=='B')
                    break;
                i+=dx[d];
                j+=dy[d];
            }
        }
        return ans;
    }
};