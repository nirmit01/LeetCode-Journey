class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
        {
            return strs[0];
        }
        sort(strs.begin(),strs.end());
        if(strs[0].size()==0)
        {
            return strs[0];
        }
        int sz=strs.size();
        int n=min(strs[0].size(),strs[sz-1].size());
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(strs[0][k]==strs[sz-1][k])
            {
                k++;
            }
        }
        return strs[0].substr(0,k);
    }
};