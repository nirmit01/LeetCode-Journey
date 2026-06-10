class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int tot=n+m;
        int i=0,j=0,cnt=0;
        int prev=0,curr=0;
        while(cnt<=tot/2)
        {
            prev=curr;
            if(i<n && (j>=m || nums1[i]<=nums2[j]))
                curr=nums1[i++];
            else
                curr=nums2[j++];
            cnt++;
        }
        if(tot%2)
            return curr;
        return (curr+prev)/2.0;
    }
};