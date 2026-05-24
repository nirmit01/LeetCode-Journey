class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> idx(n),dp(n,1);
        for(int i=0;i<n;i++)
        {
            idx[i]=i;
        }
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return arr[a]<arr[b];
        });
        for(int i:idx)
        {
            int x=1;
            int p,q;
            bool check1=true,check2=true;
            int maxi=0;
            while(x<=d)
            {
                if(i+x<n && check1 && arr[i]>arr[i+x])
                    maxi=max(maxi,dp[i+x]);
                else
                    check1=false;

                if(i-x>=0 && check2 && arr[i]>arr[i-x])
                    maxi=max(maxi,dp[i-x]);
                else
                    check2=false;
                
                if(!check1 && !check2)
                    break;
                x++;
            }
            dp[i]+=maxi;
        }
        return *max_element(dp.begin(),dp.end());
    }
};