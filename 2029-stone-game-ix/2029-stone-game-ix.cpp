class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3]={0};
        for(int i:stones)
            f[i%3]++;

        if(f[0]%2==0)
            return f[1]>0 && f[2]>0;
        
        return (f[2]-f[1])>2  || (f[1]-f[2])>2;
    }
};