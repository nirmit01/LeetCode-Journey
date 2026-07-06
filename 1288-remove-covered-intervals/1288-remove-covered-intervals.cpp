class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        int maxi=0,cnt=n;
        for(int i=0;i<n;i++)
        {
            int x=intervals[i][0],y=intervals[i][1];
            if(y<=maxi)
                cnt--;
            maxi=max(maxi,y);
        }
        return cnt;
    }
};