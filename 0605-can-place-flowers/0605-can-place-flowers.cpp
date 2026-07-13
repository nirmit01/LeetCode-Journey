class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k=flowerbed.size();
        if(n==0)
            return true;
        if(k==1)
        {
            if(flowerbed[0]==0)
                return true;
            return false;
        }
        for(int i=0;i<k;i++)
        {
            if(i>0 && i<k-1 && flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            else if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            else if(i==k-1 && flowerbed[i]==0 && flowerbed[i-1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            if(n==0)
                return true;
        }
        return false;
    }
};