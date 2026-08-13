class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    int atmost(string& word,int k)
    {
        int n=word.size();
        int l=0,ans=0;
        unordered_map<char,int> mpp;
        for(int r=0;r<n;r++)
        {
            if(!isvowel(word[r]))
            {
                mpp.clear();
                l=r+1;
                continue;
            }    
            mpp[word[r]]++;
            while(mpp.size()>k)
            {
                mpp[word[l]]--;
                if(mpp[word[l]]==0)
                    mpp.erase(word[l]);
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int countVowelSubstrings(string word) {
        return atmost(word,5)-atmost(word,4);
    }
};