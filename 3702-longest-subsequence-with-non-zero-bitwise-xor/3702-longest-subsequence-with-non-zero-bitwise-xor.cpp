class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool check=false;
        int n=nums.size();
        int x=0;
        for(int i:nums)
        {
            if(i)
                check=true;
            x^=i;
        }
        if(x)
            return n;
        return check ? n-1 : 0;
    }
};