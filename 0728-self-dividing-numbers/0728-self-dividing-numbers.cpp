class Solution {
public:
    bool check(int x)
    {
        int temp=x;
        while(x>0)
        {
            int k=x%10;
            if(k==0 || temp%k!=0)
                return false;
            x/=10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++)
        {
            if(check(i))
                ans.push_back(i);
        }
        return ans;
    }
};