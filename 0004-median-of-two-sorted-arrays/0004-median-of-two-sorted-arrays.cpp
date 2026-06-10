class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int k=(n+m)/2;
        int low=max(0,k-m),high=min(n,k);
        if(m==0)
        {
            if(n%2==0)
                return (nums1[n/2]+nums1[n/2-1])/2.0;
            else
                return nums1[n/2];
        }
        while(low<=high)
        {
            int cut1=low+(high-low)/2;
            int cut2=k-cut1;
            
            int l1 = (cut1==0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2==0) ? INT_MIN : nums2[cut2-1];

            int r1 = (cut1==n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2==m) ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1)
            {
                if((m+n)%2)
                    return min(r1,r2);
                else
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        return 0;
    }
};