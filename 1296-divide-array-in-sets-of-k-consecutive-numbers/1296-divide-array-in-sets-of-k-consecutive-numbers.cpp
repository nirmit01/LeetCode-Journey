class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k)
            return false;
        unordered_map<int,int> mpp;
        for(auto i:nums)
            mpp[i]++;
        
        for(auto num:nums)
        {
            int start=num;
            while(mpp[start-1]>0)
                start--;
            while(start<=num)
            {
                while(mpp[start]>0)
                {
                    for(int i=0;i<k;i++)
                    {
                        if(mpp[start+i]==0)
                            return false;
                        mpp[start+i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};