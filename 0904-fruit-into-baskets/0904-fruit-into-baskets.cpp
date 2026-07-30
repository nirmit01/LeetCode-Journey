class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int j=0,ans=0;
        for(int i=0;i<fruits.size();i++)
        {
            mpp[fruits[i]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[j]]--;
                if(mpp[fruits[j]]==0)
                    mpp.erase(fruits[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};