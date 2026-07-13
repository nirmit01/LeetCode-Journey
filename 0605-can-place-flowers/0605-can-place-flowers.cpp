class Solution {
public:
    bool canPlaceFlowers(vector<int>& s, int k) {
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==0 && (i==0 || s[i-1]==0) && (i==n-1 || s[i+1]==0))
            {
                s[i]=1;
                cnt++;
            }
        }
        return cnt>=k;
    }
};