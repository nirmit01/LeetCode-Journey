class Solution {
public:
    bool isval(char& c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int curr=0;
        for(int i=0;i<k;i++)
            if(isval(s[i]))
                curr++;
        int tot=curr,n=s.size();
        for(int i=k;i<n;i++)
        {
            if(isval(s[i]))
                curr++;
            if(isval(s[i-k]))
                curr--;
            tot=max(curr,tot);
        }
        return tot;
    }
};