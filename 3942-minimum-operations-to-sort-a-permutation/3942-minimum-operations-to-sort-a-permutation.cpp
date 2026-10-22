class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt1=0,cnt2=0,n=nums.size();
        int idx=(nums[0]==0 ? 0 : -1);
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])   cnt1++;
            else    cnt2++;
            
            if(nums[i]==0)
                idx=i;
        }

        if(nums[0]<nums[n-1])   cnt1++;
        else    cnt2++;

        if(min(cnt1,cnt2)>1)    return -1;
        
        if(cnt1<=cnt2)  return min(idx,n-1-idx+3);
        else    return min(idx+2,n-1-idx+1);
    }
};