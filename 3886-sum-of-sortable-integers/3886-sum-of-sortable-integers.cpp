class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> fac;
        int n=nums.size();
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                fac.push_back(i);
                if(n/i!=i)
                    fac.push_back(n/i);
            }
        }
        auto kmp =[&](const vector<int> & nums1, const vector<int> & nums2){
            int n=nums1.size(), m=nums2.size();
            vector<int> lps(m);
            int j=0;
            for(int i=1;i<m;i++)
            {
                while(j>0 && nums2[i]!=nums2[j])
                {
                    j=lps[j-1];
                }
                if(nums2[i]==nums2[j])
                    j++;
                lps[i]=j;
            }
            j=0;
            for(int i=0;i<n;i++)
            {
                while(j>0 && nums1[i]!=nums2[j])
                {
                    j=lps[j-1];
                }
                if(nums1[i]==nums2[j])
                    j++;
                if(j==m)
                    return true;
            }
            return false;
        };

        auto ch = [&](const vector<int>& nums1, const vector<int>& nums2){
            vector<int> haystack=nums1;
            haystack.insert(haystack.end(),nums1.begin(),nums1.end());
            return kmp(haystack,nums2);
        };

        int ans=0;
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int k : fac)
        {
            bool check=true;
            for(int i=0;i<n;i+=k)
            {
                int j=i+k-1;
                vector<int> hay(nums.begin()+i,nums.begin()+j+1);
                vector<int> needle(sorted.begin()+i,sorted.begin()+j+1);
                if(!ch(hay,needle))
                {
                    check=false;
                    break;
                }
            }
            if(check)
                ans+=k;
        }
        return ans;
    }
};