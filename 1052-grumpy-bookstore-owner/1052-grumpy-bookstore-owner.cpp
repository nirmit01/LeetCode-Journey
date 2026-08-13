class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0,maxi=0,curr=0;
        int l=0,n=customers.size();
        for(int r=0;r<n;r++)
        {
            if(!grumpy[r])
            {
                ans+=customers[r];
                continue;
            }
            curr+=customers[r];
            while(r-l+1>minutes)
            {
                if(grumpy[l])
                    curr-=customers[l];
                l++;
            }
            maxi=max(maxi,curr);
        }
        return maxi+ans;
    }
};