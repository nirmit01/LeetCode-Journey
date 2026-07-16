class Solution {
public:
    int mySqrt(int x) {
        int low=0, high=1e5;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long k=1ll*mid*mid;
            if(k<=x)
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};