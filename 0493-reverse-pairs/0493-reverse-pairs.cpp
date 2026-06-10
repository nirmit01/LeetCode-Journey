class Solution {
public:

    int merge(vector<int>& nums,int i,int mid,int j)
    {
        if(i>=j)
            return 0;
        int left=i,right=mid+1,cnt=0;
        for(int x=left;x<=mid;x++)
        {
            while(right<=j && nums[x]>2LL*nums[right])
                right++;
            cnt+=right-(mid+1);
        }
        right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=j)
        {
            if(nums[left]<=nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while(left<=mid)
            temp.push_back(nums[left++]);
        while(right<=j)
            temp.push_back(nums[right++]);
        
        for(int x=i;x<=j;x++)
            nums[x]=temp[x-i];
        return cnt;
    }

    int mergesort(vector<int>&nums, int i, int j)
    {
        if(i>=j)
            return 0;
        int mid=i+(j-i)/2;
        int cnt=0;
        cnt+=mergesort(nums,i,mid);
        cnt+=mergesort(nums,mid+1,j);
        cnt+=merge(nums,i,mid,j);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};