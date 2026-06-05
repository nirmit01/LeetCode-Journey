class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26),f2(26);
        for(int i=0;i<s1.size();i++)
        {
            f1[s1[i]-'a']++;
        }
        int n=s1.size(),m=s2.size();
        for(int i=0;i<m;i++)
        {
            f2[s2[i]-'a']++;
            if(i>=n)
                f2[s2[i-n]-'a']--; 
            if(f1==f2)
                return true;
        }
        return false;
    }
};