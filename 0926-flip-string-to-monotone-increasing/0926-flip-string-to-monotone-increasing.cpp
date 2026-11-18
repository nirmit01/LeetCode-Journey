class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt=0, prev=0;
        for(char c:s)
        {
            if(c=='0')  cnt=min(cnt+1,prev);
            else prev++;
        }
        return cnt;
    }
};