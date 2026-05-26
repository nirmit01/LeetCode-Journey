class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,j=n-1;
        for(int i=0;i<n && i<j;i++)
        {
            if(nums[i]==0)
            {
                while(i<j && nums[j]==0)
                {
                        j--;
                }
                if(j!=i)
                {
                    swap(nums[i],nums[j]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};