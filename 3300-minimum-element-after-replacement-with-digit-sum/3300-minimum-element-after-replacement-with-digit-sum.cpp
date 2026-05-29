class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int& i:nums)
        {
            int x=i,cnt=0;
            while(x>0)
            {
                cnt+=x%10;
                x/=10;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};