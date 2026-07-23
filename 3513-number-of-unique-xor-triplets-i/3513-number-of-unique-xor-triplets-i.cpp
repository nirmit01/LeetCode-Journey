class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(n<=2)
            return n;
        while(n>0)
        {
            n/=2;
            cnt++;
        }
        return pow(2,cnt);
    }
};