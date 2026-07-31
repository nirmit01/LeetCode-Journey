class Solution {
public:

    void solve(int i,string temp,string& digits,vector<string>& ans,unordered_map<int,string>& mpp)
    {
        int n=digits.size();
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        string& s=mpp[digits[i]-'0'];
        for(char c:s)
        {
            temp.push_back(c);
            solve(i+1,temp,digits,ans,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mpp = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},
        {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        vector<string> ans;
        string temp="";
        solve(0,temp,digits,ans,mpp);
        return ans;
    }
};