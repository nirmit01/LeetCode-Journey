class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans=0,maxi=0;
        vector<int> check(1000+1);
        for(int i:citations)
        {
            check[i]++;
            maxi=max(maxi,i);
        }
        for(int i=maxi-1;i>=0;i--)
        {
            check[i]+=check[i+1];
        }
        for(int i=1;i<=maxi;i++)
        {
            if(check[i]>=i)
                ans=i;
        }
        return ans;
    }
};