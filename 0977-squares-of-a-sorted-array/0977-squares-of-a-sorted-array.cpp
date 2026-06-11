class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=-1,j=INT_MAX;
        int n=nums.size();
        for(int x=0;x<n;x++)
        {
            if(nums[x]<0)
                i=x;
            if(nums[x]>=0 && j==INT_MAX)
            {
                j=x;
                break;
            }
        }
        vector<int> ans;
        while(i>=0 && j<n)
        {
            if(nums[j]<=abs(nums[i]))
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        while(j<n)
        {
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        while(i>=0)
        {
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        return ans;
    }
};