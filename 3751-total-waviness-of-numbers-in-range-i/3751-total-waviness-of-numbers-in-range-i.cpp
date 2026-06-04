class Solution {
public:

    int solve(int x)
    {
        if(x<101)
            return 0;
        int cnt=0,a,b,c;
        a=x%10, x/=10;
        b=x%10, x/=10;
        while(x>0)
        {
            c=x%10;
            if((b>c && b>a) || (b<c && b<a))
                cnt++;
            a=b,b=c;
            x/=10;
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++)
        {
            cnt+=solve(i);
        }
        return cnt;
    }
};