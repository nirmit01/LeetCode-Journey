class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
           return nums[0];
        if(n==k)
           return *max_element(nums.begin(), nums.end());
        if(k==1)
        {
            sort(nums.rbegin(),nums.rend());
            int i=0;
            while(i<n)
            {
                int curr=nums[i],j=i;
                while(j<n && nums[i]==nums[j])
                {
                   j++;
                }
                if(j-i==1)
                   return nums[i];
                i=j;
            }
            return -1;
        }
         
        if(nums[0]==nums[n-1])
           return -1;
          
        int cnt0=1,cnt1=1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==nums[0])
               cnt0++;
            if(nums[i]==nums[n-1])
               cnt1++;    
        }
        if(cnt0>1 && cnt1>1)
           return -1;
        if(cnt0>1)
           return nums[n-1];
        if(cnt1>1)
           return nums[0];
        return max(nums[0],nums[n-1]);
    }
};