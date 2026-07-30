class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ans(n);
        vector<int> tails;
        for(int i=0;i<n;i++)
        {
            int pos = upper_bound(tails.begin(),tails.end(),obstacles[i])-tails.begin();
            ans[i]=pos+1;
            if(pos==tails.size())
                tails.push_back(obstacles[i]);
            else
                tails[pos]=obstacles[i];
        }
        return ans;
    }
};