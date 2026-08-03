class Solution {
public:
    long long gcd(int a,int b)
    {
        while(b>0)
        {
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long g=gcd(nums[i],nums[j]);
                long long st= (1ll*nums[i]*nums[j])/(g*g);
                ans=max(ans,st);
            }
        }
        return ans;
    }
};