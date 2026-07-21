class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i=0,n=s.size();
        vector<pair<int,int>> vec;
        while(i<n)
        {
            int cnt=0;
            while(s[i]=='1')
            {
                cnt++;
                i++;
            }
            if(cnt>0)
                vec.push_back({cnt,1});
            cnt=0;
            while(s[i]=='0')
            {
                cnt++;
                i++;
            }
            if(cnt>0)
                vec.push_back({cnt,0});
        }
        int sz=vec.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                ans++;
        }
        int maxi=0;
        for(int i=1;i<sz-1;i++)
        {
            if(vec[i].second==1 && vec[i-1].second==0 && vec[i+1].second==0)
            {
                maxi=max(maxi,vec[i-1].first+vec[i+1].first);
            }
        }
        return ans+maxi;
    }
};