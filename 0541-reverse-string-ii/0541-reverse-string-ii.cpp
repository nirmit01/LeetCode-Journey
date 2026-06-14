class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        int i=0;
        while(i<n)
        {
            int end=i+2*k;
            int j=min(i+k-1,n-1);
            while(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            i=end;
        }
        return s;
    }
};