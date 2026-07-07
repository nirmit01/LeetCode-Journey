class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,ans=0;
        string s=to_string(n);
        for(char c:s)
        {
            if(c!='0')
            {
                int x=c-'0';
                ans=ans*10+x;
                sum+=x;
            }
        }
        return ans*sum;
    }
};