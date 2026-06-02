class Solution {
public:
    void solve(int i,string& s,int cnt,vector<string>& ans,string temp)
    {
        if(cnt==4 && i==(int)s.size())
        {
            ans.push_back(temp);
            return;
        }
        if(i==(int)s.size())  return;
        if(cnt==4)  return;
        if(cnt>0 && cnt<=3)
            temp+='.';
        string ch=temp;
        if(s[i]=='0')
        {
            temp+='0';
            solve(i+1,s,cnt+1,ans,temp);
            return;
        }
        int n=s.size();
        string dig="";
        for(int j=i;j<i+3 && j<n;j++)
        {
            dig+=s[j];
            int d=stoi(dig);
            if(d<=255)
            {
                ch=temp+dig;
                solve(j+1,s,cnt+1,ans,ch);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string temp="";
        vector<string> ans;
        solve(0,s,0,ans,temp);
        return ans;
    }
};