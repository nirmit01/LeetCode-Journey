class Solution {
public:
    string winningPlayer(int x, int y) {
        string ans;
        int k=y/4;
        if(x>=k)
        {
            if(k%2)
                ans="Alice";
            else
                ans="Bob";
        }
        else
        {
            if(x%2)
                ans="Alice";
            else
                ans="Bob";
        }
        return ans;
    }
};