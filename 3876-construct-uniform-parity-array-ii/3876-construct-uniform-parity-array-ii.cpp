class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0, eve=0;
        int mino=INT_MAX, mine=INT_MAX;
        int n=nums1.size();
        for(int x:nums1)
        {
            if(x%2)
            {
                odd++;
                mino=min(mino,x);
            }
            else
            {
                eve++;
                mine=min(mine,x);
            }
        }
        if(eve==0 || odd==0)
            return true;
        int cnt=0;
        for(int x:nums1)
        {
            if(x%2)
                cnt++;
            else if((x-mino)>=1)
                cnt++;
        }
        if(cnt==n)
            return true;
        
        cnt=0;
        for(int x:nums1)
        {
            if(x%2==0)
                cnt++;
            else if(x-mino>=1)
                cnt++;
        }
        return cnt==n;
        
    }
};