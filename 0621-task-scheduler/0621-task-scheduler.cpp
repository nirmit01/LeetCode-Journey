class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        int m=tasks.size();
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            mpp[tasks[i]]++;
            maxi=max(maxi,mpp[tasks[i]]);
        }
        int cnt=0;
        for(auto it:mpp)
        {
            if(it.second==maxi)
                cnt++;
        }
        return max(m,(maxi-1)*(n+1)+cnt);
    }
};