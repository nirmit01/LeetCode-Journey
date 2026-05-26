class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> vec(26);
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<97)
                vec[word[i]-'A']=1;
        }
        int cnt=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='a' && word[i]<='z' && vec[word[i]-'a'])
            {
                vec[word[i]-'a']=0;
                cnt++;
            }
        }
        return cnt;
    }
};