class Solution {
public:
    const int mod=1e9+7;
    int score(vector<int>& nums,int k)
    {
        int n=nums.size();
        int ans=INT_MIN,curr=0;
        for(int i=0;i<n;i++)
        {
            int x = (nums[i]%k) ? -nums[i] : nums[i];
            curr+=x;
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        return ans;
    }
    int divisibleGame(vector<int>& nums) {
        unordered_set<int> st;
        int maxi=0;
        for(int x:nums)
        {
            maxi=max(maxi,x);
            if(x>1)
                st.insert(x);
            for(int i=2;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    st.insert(i);
                    if(i!=x/i)
                        st.insert(x/i);
                }
            }
        }
        st.insert(2);
        long long ans=INT_MIN;
        int k=0;
        for(auto it:st)
        {
            int x=score(nums,it);
            if(x>ans)
            {
                ans=x;
                k=it;
            }
            else if(x==ans)
                k=min(k,it);
        }
        return ((ans*k)%mod+mod)%mod;
    }
};