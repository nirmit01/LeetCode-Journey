class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=0,eve=0,c1=1,c2=2;
        for(int i=0;i<n;i++)
        {
            odd+=c1;
            eve+=c2;
            c1+=2;
            c2+=2;
        }
        while(odd!=0)
        {
            int temp=odd;
            odd=eve%odd;
            eve=temp;
        }
        return eve;
    }
};