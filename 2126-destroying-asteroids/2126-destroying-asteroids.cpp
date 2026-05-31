class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr=mass;
        int n=asteroids.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(curr>=asteroids[i]){
                curr+=asteroids[i];
                asteroids[i]=0;
            }
            else{
                cnt++;
            }
        }
        while(cnt>0){
            int temp=0;
            for(int i=0;i<n;i++){
                if(curr>=asteroids[i]){
                    curr+=asteroids[i];
                    asteroids[i]=0;
                }
                else{
                    temp++;
                }
            }
            if(temp==cnt)
                return false;
            cnt=temp;
        }
        return true;
    }
};