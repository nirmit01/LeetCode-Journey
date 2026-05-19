class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt=0;
        if(k==1)
        {
            return r-l+1;
        }
        int x=ceil(pow(l,1.0/k));
        while(true)
        {
            int y=pow(x,k);
            if(y>=l && y<=r)
                cnt++;
            else
                return cnt;
            x++;
        }
        return cnt;
    }
};