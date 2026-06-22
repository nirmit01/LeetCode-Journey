class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(char c:text)
            mpp[c]++;
        int ans=min(mpp['b'],min(mpp['a'],min(mpp['n'],min(mpp['l']/2,mpp['o']/2))));
        return ans;
    }
};