class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long curr=1,ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                curr++;
            }
            else{
                curr=1;
            }
            ans+=curr;
        }
        return ans;
    }
};