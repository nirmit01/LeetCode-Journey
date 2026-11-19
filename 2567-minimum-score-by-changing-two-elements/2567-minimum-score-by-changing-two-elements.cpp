class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int a1=0,a2=0,a3=0,b1=INT_MAX,b2=INT_MAX,b3=INT_MAX;
        for(int i:nums)
        {
            if(a1<i)    {a3=a2;a2=a1;a1=i;}
            else if(a2<i)   {a3=a2;a2=i;}
            else if(a3<i)   {a3=i;}

            if(b1>i)    {b3=b2;b2=b1;b1=i;}
            else if(b2>i)   {b3=b2;b2=i;}
            else if(b3>i)   {b3=i;}
        }
        return min(a2-b2,min(a3-b1,a1-b3));
    }
};