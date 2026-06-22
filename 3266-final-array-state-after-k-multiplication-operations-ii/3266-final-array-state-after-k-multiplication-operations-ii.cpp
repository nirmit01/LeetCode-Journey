class Solution {
public:
    const int mod=1e9+7;
    long long binexp(int n, int k)
    {
        long long ans=1,a=n%mod;
        while(k>0)
        {
            if(k&1)
                ans=(ans*a)%mod;
            a=(a*a)%mod;
            k>>=1;
        }
        return ans;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)
            return nums;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        int n =nums.size(),maxi=-1;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
            maxi=max(maxi,nums[i]);
        }
        while(k>0)
        {
            auto x=pq.top();
            pq.pop();
            x.first=x.first*multiplier;
            pq.push(x);
            k--;
            if(x.first>maxi)
                break;
        }
        int rem=k%n, t=k/n;
        vector<int> ans(n);
        long long m1=binexp(multiplier,t),m2=(m1*multiplier)%mod;
        while(rem--)
        {
            auto x=pq.top();
            pq.pop();
            x.first = (x.first%mod*m2)%mod;
            ans[x.second]=x.first;
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            x.first = (x.first%mod*m1)%mod;
            ans[x.second]=x.first;   
        }
        return ans;
    }
};