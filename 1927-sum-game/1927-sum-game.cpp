class Solution {
public:
    bool sumGame(string num) {
        int marks=0, q1=0, q2=0;
        int n=num.size();
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?')
                marks++;
            else
                q1+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?')
                marks--;
            else
                q2+=(num[i]-'0');
        }
        if(marks%2!=0)
            return true;
        return q2-q1!=9*marks/2;
    }
};