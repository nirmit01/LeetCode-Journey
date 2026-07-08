long long pow10[100001];
const int mod=1e9+7;
int init=[](){
    pow10[0]=1;
    for(int i=1;i<100001;i++)
        pow10[i]=(pow10[i-1]*10)%mod;
    return 0;
}();
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> dig,pos;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='0')
            {
                dig.push_back(s[i]-'0');
                pos.push_back(i);
            }
        }
        int k=dig.size();
        vector<int> pref(k+1);
        vector<long long> conc(k+1);
        for(int i=0;i<k;i++)
        {
            pref[i+1]=pref[i]+dig[i];
            conc[i+1]=((conc[i]*10ll)%mod+dig[i])%mod;
        }
        vector<int> ans;
        for(auto& v:queries)
        {
            int l=lower_bound(pos.begin(),pos.end(),v[0])-pos.begin();
            int r=upper_bound(pos.begin(),pos.end(),v[1])-pos.begin();
            int cur=pref[r]-pref[l];
            long long x=(conc[r]-(conc[l]*pow10[r-l])%mod + mod)%mod;
            ans.push_back((x*cur)%mod);
        }
        return ans;
    }
};