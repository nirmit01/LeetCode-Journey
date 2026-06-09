class Solution {
public:
    string removeDuplicates(string s) {
        int i=0,n=s.size();
        string ans;
        while(i<n)
        {
            if(ans.size()==0 || ans[ans.size()-1]!=s[i])
                ans.push_back(s[i]);
            else
                ans.pop_back();
            i++;
            
        }
        return ans;
    }
};