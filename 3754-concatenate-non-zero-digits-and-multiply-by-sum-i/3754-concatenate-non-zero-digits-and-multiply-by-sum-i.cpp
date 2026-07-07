class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,ans=0;
        int r=1;
        while(n>0)
        {
            int x=n%10;
            n/=10;
            if(x==0)    continue;
            sum+=x;
            ans=ans+x*r;
            r*=10;
        }
        return ans*sum;
    }
};