class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                if(mat[i][mid]>mat[maxi][mid])
                {
                    maxi=i;
                }
            }
            int left = (mid==0) ? -1 : mat[maxi][mid-1];
            int right = (mid==m-1) ? -1 : mat[maxi][mid+1];
            if(mat[maxi][mid]>left && mat[maxi][mid]>right)
                return {maxi,mid};
            else if(mat[maxi][mid]<left)
                high=mid-1;
            else
                low=mid+1;
        }
        return {-1,-1};   
    }
};