class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first=nums[0],second=LLONG_MIN,third=LLONG_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==first || nums[i]==second || nums[i]==third)
                continue;
            if(nums[i]>first)
            {
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]<first && nums[i]>second)
            {
                third=second;
                second=nums[i];
            }
            else if(nums[i]<second && nums[i]>third)
                third=nums[i];
        }
        if(third==LLONG_MIN)
            return first;
        return third;
    }
};