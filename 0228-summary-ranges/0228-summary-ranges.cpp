class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=1,n=nums.size();
        if(n==0)
            return {};
        int l=nums[0],r=nums[0];
        vector<string> ans;
        while(i<n)
        {
            if(nums[i]==(nums[i-1]+1))
                r=nums[i];
            else
            {
                if(l==r)
                    ans.push_back(to_string(l));
                else
                    ans.push_back(to_string(l)+"->"+to_string(r));
                l=nums[i];
                r=nums[i];
            }
            i++;
        }
        if(l==r)
            ans.push_back(to_string(l));
        else
            ans.push_back(to_string(l)+"->"+to_string(r));
        return ans;
    }
};