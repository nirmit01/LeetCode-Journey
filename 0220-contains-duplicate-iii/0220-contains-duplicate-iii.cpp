class Solution {
public:
    int getbucket(int n,int width)
    {
        if(n<0)
            return (n+1)/width-1;
        return n/width;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int width=valueDiff+1;
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int id=getbucket(nums[i],width);
            if(mpp.count(id))
                return true;
            else if(mpp.count(id-1) && (nums[i]-mpp[id-1])<=valueDiff)
                return true;
            else if(mpp.count(id+1) && (mpp[id+1]-nums[i])<=valueDiff)
                return true;
            mpp[id]=nums[i];
            if(mpp.size()>indexDiff)
            {
                int id=getbucket(nums[i-indexDiff],width);
                mpp.erase(id);
            }
        }
        return false;
    }
};