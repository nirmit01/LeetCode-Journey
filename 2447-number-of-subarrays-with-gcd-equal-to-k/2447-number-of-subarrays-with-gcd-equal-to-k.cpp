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
        vector<pair<int,int>> prev;
        int ans=0;
        for(int i:nums)
        {
            vector<pair<int,int>> curr;
            curr.push_back({i,1});
            for(auto& [g,cnt] : prev)
            {
                int ng=gcd(g,i);
                
                if(curr.back().first==ng)
                {
                    curr.back().second+=cnt;
                }
                else
                {
                    curr.push_back({ng,cnt});
                }
            }
            for(auto& [g,cnt] : curr)
            {
                if(g==k)
                    ans+=cnt;
            }
            prev=curr;
        }
        return  ans;
    }
};