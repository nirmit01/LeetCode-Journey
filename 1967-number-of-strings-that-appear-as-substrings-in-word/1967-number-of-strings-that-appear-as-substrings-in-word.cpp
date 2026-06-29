class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        int n=word.size();
        for(string s:patterns)
            if(word.find(s)!=string::npos)
                cnt++;
        return cnt;
    }
};