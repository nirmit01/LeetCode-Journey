class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int sum1=0,sum2=0;
        int maxi1=0,maxi2=0,curr1=0,curr2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            int diff=(nums1[i]-nums2[i]);
            curr1+=diff;
            curr2+=(-1*diff);
            
            if(curr1<0)
                curr1=0;
            else
                maxi1=max(maxi1,curr1);
            
            if(curr2<0)
                curr2=0;
            else
                maxi2=max(maxi2,curr2);
        }
        return max(sum1+maxi2,sum2+maxi1);
    }
};