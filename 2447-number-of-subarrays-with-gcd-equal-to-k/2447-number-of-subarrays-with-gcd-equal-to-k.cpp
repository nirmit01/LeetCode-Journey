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
        unordered_map<int,int> prev;
        int ans=0;
        for(int i:nums)
        {
            unordered_map<int,int> curr;
            curr[i]++;
            for(auto& [g,cnt] : prev)
            {
                int ng=gcd(g,i);
                curr[ng]+=cnt;
            }
            if(curr.count(k))
            {
                ans+=curr[k];
            }
            prev=curr;
        }
        return  ans;
    }
};