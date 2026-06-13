class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3);
        int n=triplets.size();
        auto &t=triplets;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(found[i])
                    break;
                if(t[j][i]==target[i] && t[j][0]<=target[0] && t[j][1]<=target[1] && 
                t[j][2]<=target[2])
                {
                    if(t[j][0]==target[0])  found[0]=true;
                    if(t[j][1]==target[1])  found[1]=true;
                    if(t[j][2]==target[2])  found[2]=true;
                }
            }
        }
        return (found[0] && found[1] && found[2]);
    }
};