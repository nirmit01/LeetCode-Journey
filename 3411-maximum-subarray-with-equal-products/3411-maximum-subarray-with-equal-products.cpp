class Solution {
public:
    long long hcf(long long a,long long b)
    {
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=2;
        for(int i=0;i<n;i++)
        {
            long long prod=1;
            long long g=1,l=1;
            for(int j=i;j<n;j++)
            {
                prod*=nums[j];
                if(prod>2520)
                    break;
                if(i==j)
                    g=nums[j];
                else
                    g=gcd(g,nums[j]);
                
                l= (l/gcd(l,nums[j]))*nums[j];
                if(prod==g*l)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};