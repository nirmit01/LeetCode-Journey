class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt=0;
        unordered_map<int,int> mpp;
        int n=row.size();
        for(int i=0;i<n;i++)
        {
            mpp[row[i]]=i;
        }
        for(int i=0;i<n-1;i+=2)
        {
            int k=row[i]^1;
            if(row[i+1]!=k)
            {
                int x=mpp[k];
                mpp[k]=i+1;
                mpp[row[i+1]]=x;
                swap(row[x],row[i+1]);
                cnt++;
            }
        }
        return cnt;
    }
};