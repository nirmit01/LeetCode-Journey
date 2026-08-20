class Solution {
public:
    Solution()
    {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base :: sync_with_stdio(false);
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int left=0;left<m;left++)
        {
            for(int right=left;right<m;right++)
            {
                unordered_map<int,int> freq;
                freq[0]=1;
                int tot=0;
                for(int i=0;i<n;i++)
                {
                    if(left>0)
                        tot+=matrix[i][right]-matrix[i][left-1];
                    else
                        tot+=matrix[i][right];
                    auto it=freq.find(tot-target);
                    if(it!=freq.end())
                        ans+=it->second;
                    freq[tot]++;
                }
            }
        }
        return ans;
    }
};