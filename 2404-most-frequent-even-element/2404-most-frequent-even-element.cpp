class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i:nums)
        {
            if(i%2==0)
                mpp[i]++;
        }
        int ans=-1,maxi=0;
        for(auto [x,freq]:mpp)
        {
            if(freq>maxi || (freq==maxi && x<ans))
            {
                maxi=freq;
                ans=x;
            }
        }
        return ans;
    }
};