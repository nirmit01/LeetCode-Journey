class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const auto& a, const auto& b){
            return a.size()<b.size();
        });
        unordered_map<string,int> mpp;
        for(auto& i:words)
            mpp[i]=1;
        int ans=1;
        for(auto& s:words)
        {
            int n=s.size();
            for(int i=0;i<n;i++)
            {
                string temp= s.substr(0,i)+s.substr(i+1);
                if(mpp.count(temp))
                {
                    mpp[s]=max(mpp[s],mpp[temp]+1);
                }
            }
            ans=max(ans,mpp[s]);
        }
        return ans;
    }
};