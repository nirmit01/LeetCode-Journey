class Solution {
public:
    int gcd(int a,int b)
    {
        if(a==b)
            return a;
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int g=nums[i];
            for(int j=i;j<n;j++)
            {
                g=gcd(g,nums[j]);
                if(g==k)
                    cnt++;
                if(g<k)
                    break;
            }
        }
        return cnt;
    }
};