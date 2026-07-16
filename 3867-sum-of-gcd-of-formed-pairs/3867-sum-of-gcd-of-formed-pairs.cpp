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
    long long gcdSum(vector<int>& nums) {
        int n=nums.size(),maxi=INT_MIN;
        vector<int> pref(n);
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            pref[i]=gcd(maxi,nums[i]);
        }
        sort(pref.begin(),pref.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j)
        {
            ans+=gcd(pref[i],pref[j]);
            i++;
            j--;
        }
        return ans;
    }
};