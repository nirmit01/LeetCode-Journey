class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int id=1,n=arr.size();
        unordered_map<int,int> mpp;
        int i=0;
        while(i<n)
        {
            int curr=temp[i];
            mpp[curr]=id;
            while(i<n && temp[i]==curr)
            {
                i++;
            }
            id++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=mpp[arr[i]];
        return ans;
    }
};