class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int ans=0;
        for(int top=0;top<n;top++)
        {
            vector<int> pref(m);
            for(int bottom=top;bottom<n;bottom++)
            {
                for(int i=0;i<m;i++)
                    pref[i]+=matrix[bottom][i];
                
                unordered_map<int,int> freq;
                freq[0]=1;
                int tot=0;
                for(int i=0;i<m;i++)
                {
                    tot+=pref[i];
                    if(freq[tot-target])
                        ans+=freq[tot-target];
                    freq[tot]++;
                }
            }
        }
        return ans;
    }
};