class Solution {
public:
    int n;

    void solve(int idx,string& s,vector<string> vec, vector<vector<string>>& ans)
    {
        string temp;
        if(idx==n)
        {
            ans.push_back(vec);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            temp+=s[i];
            string k=temp;
            reverse(k.begin(),k.end());
            if(k==temp)
            {
                vec.push_back(temp);
                solve(i+1,s,vec,ans);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        n=s.size();
        solve(0,s,temp,ans);
        return ans;
    }
};