class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int sum1=0,sum2=0;
        vector<int> v1(n),v2(n);
        for(int i=0;i<n;i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            v1[i]=(nums1[i]-nums2[i]);
            v2[i]=(nums2[i]-nums1[i]);
        }
        int maxi1=0,maxi2=0,curr1=0,curr2=0;
        for(int i=0;i<n;i++)
        {
            curr1+=v1[i];
            maxi1=max(maxi1,curr1);
            if(curr1<0)
            {
                curr1=0;
            }

            curr2+=v2[i];
            maxi2=max(maxi2,curr2);
            if(curr2<0)
            {
                curr2=0;
            }
        }
        return max(sum1+maxi2,sum2+maxi1);
    }
};