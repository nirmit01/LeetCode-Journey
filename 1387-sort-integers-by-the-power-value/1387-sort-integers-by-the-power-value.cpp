class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> vec;
        for(int i=lo;i<=hi;i++)
        {
            int n=i;
            int ans=0;
            while(n!=1)
            {
                if(n%2)
                    n=3*n+1;
                else
                    n/=2;
                ans++;
            }
            vec.push_back({ans,i});
        }
        sort(vec.begin(),vec.end());
        return vec[k-1].second;
    }
};