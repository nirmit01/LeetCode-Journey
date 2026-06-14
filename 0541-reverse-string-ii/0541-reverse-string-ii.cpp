class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        int i=0,j=min(i+k-1,n-1),end=i+2*k;
        while(i<n)
        {
            while(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            i=end;
            j=min(i+k-1,n-1);
            end=i+2*k;
        }
        return s;
    }
};