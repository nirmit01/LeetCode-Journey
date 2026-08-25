class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> vec(101);
        for(int i:nums)
           vec[i]=1;
        int j=k;
        while(j<=100)
        {
            if(!vec[j])
               return j;
            j+=k;
        }
        return (100/k + 1)*k;
    }
};