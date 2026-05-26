class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> even(k),odd(k);
        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
                odd[nums[i]%k]++;
            else
                even[nums[i]%k]++;
        }
        vector<int> ec(k),oc(k);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                int dist=min((j-i+k)%k,(i-j+k)%k);
                ec[i]+=dist*even[j];
                oc[i]+=dist*odd[j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(i==j)
                    continue;
                ans=min(ans,ec[i]+oc[j]);
            }
        }
        return ans;
    }
};