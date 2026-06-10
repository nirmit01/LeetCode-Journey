class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            while(i<n)
            {
                char c=s[i];
                if(c<97)
                    c=c-'A'+'a';
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    break;
                i++;
            }
            while(j>=0)
            {
                char c=s[j];
                if(c<97)
                    c=c-'A'+'a';
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    break;
                j--;
            }
            if(i<=j)
                swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};