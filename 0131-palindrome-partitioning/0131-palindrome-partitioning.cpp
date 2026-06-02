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
            if(ispal(temp))
            {
                vec.push_back(temp);
                solve(i+1,s,vec,ans);
                vec.pop_back();
            }
        }
    }
    bool ispal(string& temp)
    {
        int i=0,j=temp.size()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        n=s.size();
        solve(0,s,temp,ans);
        return ans;
    }
};