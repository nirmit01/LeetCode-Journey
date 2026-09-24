class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int tot=0;
            while(x>0)
            {
                tot+=x%10;
                x/=10;
            }
            if(tot==i)
                return i;
        }
        return -1;
    }
};