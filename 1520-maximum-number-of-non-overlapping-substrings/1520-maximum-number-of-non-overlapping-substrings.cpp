class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> first(26,-1), last(26,-1);
        for(int i=0;i<n;i++)
        {
            int k=s[i]-'a';
            if(first[k]==-1)
                first[k]=i;
            last[k]=i;
        }
        vector<pair<int,int>> candidates;
        for(int i=0;i<26;i++)
        {
            if(first[i]==-1)
                continue;
            int l=first[i],r=last[i];
            bool check=true;
            for(int j=l;j<=r;j++)
            {
                int k=s[j]-'a';
                if(first[k]<l)
                {
                    check=false;
                    break;
                }
                r=max(r,last[k]);
            }
            if(check)
            {
                candidates.push_back({l,r});
            }
        }

        sort(candidates.begin(),candidates.end(),[](const auto &a, const auto &b){
            return a.second<b.second;
        });
        vector<string> ans;
        int prev=-1;
        for(const auto& [l,r]: candidates)
        {
            if(l>prev)
            {
                ans.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }
        return ans;
    }
};