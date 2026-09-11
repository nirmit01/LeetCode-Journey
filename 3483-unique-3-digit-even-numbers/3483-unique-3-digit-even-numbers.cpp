class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j || j==k || k==i)
                        continue;
                    
                    if(nums[i]==0 || nums[k]%2)
                        continue;
                    
                    int digit= nums[i]*100 + nums[j]*10 + nums[k];
                    st.insert(digit);
                }
            }
        }
        return st.size();
    }
};