class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp=nums;
        while(temp.size()>1)
        {
            int n=temp.size();
            vector<int> v(n-1);
            for(int i=0;i<n-1;i++)
            {
                v[i]=(temp[i]+temp[i+1])%10;
            }
            temp=v;
        }
        return temp[0];
    }
};