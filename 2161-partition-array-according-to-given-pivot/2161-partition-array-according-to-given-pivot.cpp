class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int c1=0,c2=0,c3=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
                c1++;
            else if(nums[i]>pivot)
                c3++;
            else
                c2++;
        }
        vector<int> ans(n);
        int a=0,j=c1,z=c1+c2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
                ans[a++]=nums[i];
            else if(nums[i]>pivot)
                ans[z++]=nums[i];
            else
                ans[j++]=nums[i];
        }
        return ans;
    }
};