class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(auto &s : knowledge)
        {
            mpp[s[0]]=s[1];
        }
        string ans="";
        bool addkey=false;
        string curr="";
        for(char c:s)
        {
            if(c=='(')
                addkey=true;
            else if(c==')')
            {
                if(mpp.count(curr))
                    ans+=mpp[curr];
                else
                    ans+='?';
                addkey=false;
                curr.clear();
            }
            else
            {
                if(addkey)
                    curr+=c;
                else
                    ans+=c;
            }
        }
        return ans;
        
    }
};