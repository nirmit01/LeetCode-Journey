class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        int ans=INT_MIN;
        for(int i:nums)
        {
            st.insert(i);
            ans=max(ans,i);
        }
        if(st.size()<3)
            return ans;
        int max2=INT_MIN,max3=INT_MIN;
        for(int i:st)
        {
            if(i<ans && i>max2)
            {
                max3=max2;
                max2=i;
            }
            if(i<max2 && i>max3)
                max3=i;
        }
        return max3;
    }
};