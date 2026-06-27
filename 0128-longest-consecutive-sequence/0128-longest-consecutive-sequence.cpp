class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int x:nums)
        {
            st.insert(x);
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        
        int ans=0;
        for(int x:st)
        {
            if(st.find(x-1)==st.end())
            {
                int curr=x,len=1;
                while(st.find(curr+1)!=st.end())
                {
                    len++;
                    curr++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};