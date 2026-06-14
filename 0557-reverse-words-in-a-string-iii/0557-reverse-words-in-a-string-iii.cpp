class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j<n && s[j]!=' ')
                j++;
            int end=j;
            j-=1;
            while(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            i=end+1;
        }
        return s;
        
        
    }
};