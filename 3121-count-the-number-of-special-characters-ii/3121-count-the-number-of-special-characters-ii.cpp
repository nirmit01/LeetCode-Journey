static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int> mpp(26,-1);
        for(int i=0;i<n;i++)
        {
            if(word[i]>=97)
                mpp[word[i]-'a']=i;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]<97)
            {
                int k=word[i]-'A';
                if(mpp[k]!=-1)
                {
                    if(mpp[k]<i)
                        cnt++;
                    mpp[k]=-1;
                }
            }
        }
        return cnt;
    }
};