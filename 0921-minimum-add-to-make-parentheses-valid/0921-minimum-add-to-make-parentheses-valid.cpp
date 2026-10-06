class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0,req=0;
        for(char c:s)
        {
            if(c=='(')
                open++;
            else
            {
                if(open>close)
                    close++;
                else
                    req++;
            }
        }
        if(open>close)  
            req+=(open-close);
        return req;
    }
};