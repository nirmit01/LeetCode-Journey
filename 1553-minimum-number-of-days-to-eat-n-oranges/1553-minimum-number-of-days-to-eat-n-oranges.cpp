class Solution {
public:
    unordered_map<long long,long long> mpp;
    int minDays(int n) {
        if(n<=1)
            return 1;
        if(mpp.count(n))
            return mpp[n];
        
        int a1 = n%2 + minDays(n/2);
        int a2 = n%3 + minDays(n/3);
        return mpp[n]=1+min(a1,a2);
    }
};