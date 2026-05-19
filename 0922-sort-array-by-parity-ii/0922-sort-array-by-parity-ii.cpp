class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int p=0,q=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[p]=nums[i];
                p+=2;
            }
            else
            {
                ans[q]=nums[i];
                q+=2;
            }
        }
        return ans;
    }
};