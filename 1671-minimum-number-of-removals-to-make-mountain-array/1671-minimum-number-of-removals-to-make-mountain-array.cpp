class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n),right(n);
        vector<int> tails;
        for(int i=0;i<n;i++)
        {
            int pos=lower_bound(tails.begin(),tails.end(),nums[i])-tails.begin();
            left[i]=pos+1;
            if(pos==tails.size())
                tails.push_back(nums[i]);
            else
                tails[pos]=nums[i];
        }
        tails=vector<int>();
        for(int i=n-1;i>=0;i--)
        {
            int pos=lower_bound(tails.begin(),tails.end(),nums[i])-tails.begin();
            right[i]=pos+1;

            if(pos==tails.size())
                tails.push_back(nums[i]);
            else
                tails[pos]=nums[i];
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(left[i]!=1 && right[i]!=1)
                ans=max(ans,left[i]+right[i]-1);
        }

        return n-ans;
    }
};