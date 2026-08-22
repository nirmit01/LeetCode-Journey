class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1;
        int temp=n;
        while(temp>0)
        {
            int a=temp%10;
            temp/=10;
            sum+=a;
            prod*=a;
        }
        return (n%(sum+prod)==0);
    }
};