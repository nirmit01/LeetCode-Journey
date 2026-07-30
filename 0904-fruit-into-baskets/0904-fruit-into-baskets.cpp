class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int j=0,n=fruits.size();
        int ans=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(mpp[fruits[i]]==0)
                cnt++;
            mpp[fruits[i]]++;
            while(cnt>2)
            {
                mpp[fruits[j]]--;
                if(mpp[fruits[j]]==0)
                    cnt--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};