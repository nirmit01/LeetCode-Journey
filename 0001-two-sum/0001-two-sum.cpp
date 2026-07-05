class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector <int> ans(2);
        // unordered_map <int,int> mpp;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int x=target-nums[i];
        //     if(mpp.find(x)!=mpp.end())
        //     {
        //         ans[0]=i;
        //         ans[1]=mpp.find(x)->second;
        //         break;
        //     }
        //     mpp[nums[i]]=i;
        // }
        // return ans;

        vector<pair<int,int>> v;
        int n =nums.size();
        int l=0,r=n-1;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        while(l<r)
        {
            if(v[l].first+v[r].first==target)
            {
                return {v[l].second,v[r].second};
            }
            else if(v[l].first+v[r].first<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {v[l].second,v[r].second};
    }
};