class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,int> mpp;
        for(string& s:strs)
        {
            string temp=s;
            sort(temp.begin(),temp.end());
            if(mpp.count(temp))
            {
                ans[mpp[temp]].push_back(s);
            }
            else
            {
                ans.push_back({s});
                mpp[temp]=ans.size()-1;
            }
        }
        return ans;
    }
};