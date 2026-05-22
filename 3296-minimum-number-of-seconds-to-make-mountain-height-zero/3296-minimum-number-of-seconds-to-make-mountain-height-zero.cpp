class Solution {
public:
    long long minNumberOfSeconds(int k, vector<int>& vec) {
        int n=vec.size();
        long long low=1,high=1LL*(*min_element(vec.begin(),vec.end()))*k*(k+1)/2;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                int r=(-1+sqrt(1+(8*mid)/vec[i]))/2; 
                maxi+=r;
                if(maxi>k)
                {
                    break;
                }
            }
            if(maxi>=k)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};