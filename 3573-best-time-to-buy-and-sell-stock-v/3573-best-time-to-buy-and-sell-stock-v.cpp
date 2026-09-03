class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        long long mini=LLONG_MIN;
        vector<long long> free(k+1,mini), shor(k+1,mini), lon(k+1,mini);
        free[0]=0;
        for(int p : prices)
        {
            vector<long long> newfree=free, newshor=shor, newlon=lon;

            for(int i=0;i<=k;i++)
            {
                if(free[i]!=mini){
                    newlon[i]=max(newlon[i],free[i]-p);
                    newshor[i]=max(newshor[i], free[i]+p);
                }

                if(i<k && lon[i]!=mini){
                    newfree[i+1]=max(newfree[i+1], lon[i]+p);
                }

                if(i<k && shor[i]!=mini){
                    newfree[i+1]=max(newfree[i+1], shor[i]-p);
                }
            }

            free=newfree;
            lon=newlon;
            shor=newshor;
        }

        long long ans=0;
        for(auto x:free)
            ans=max(ans,x);
        return ans;
    }
};