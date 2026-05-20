class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> vec(n+1);
        int cnt=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(++vec[A[i]]==2)
                cnt++;
            if(++vec[B[i]]==2)
                cnt++;
            ans[i]=cnt;
        }
        return ans;
    }
};