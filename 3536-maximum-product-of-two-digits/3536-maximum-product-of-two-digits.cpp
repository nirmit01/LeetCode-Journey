class Solution {
public:
    int maxProduct(int n) {
        int maxi1=0,maxi2=0;
        while(n>0)
        {
            int x=n%10;
            n/=10;
            if(x>maxi1)
            {
                maxi2=maxi1;
                maxi1=x;
            }
            else if(x>maxi2)
            {
                maxi2=x;
            }
        }   
        return maxi1*maxi2;
    }
};