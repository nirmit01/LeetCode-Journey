class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,maxi=0;
        while(l<r)
        {
            maxi=max((min(height[l],height[r]))*(r-l),maxi);
            if(height[l]>height[r])
            {
                r--;
            }
            else if(height[l]<height[r])
            {
                l++;
            }
            else if(height[l]==height[r])
            {
                if(height[l+1]<=height[r-1])
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return maxi;
    }
};