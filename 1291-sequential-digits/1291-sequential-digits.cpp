class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=2;i<=9;i++)
        {
            for(int j=1;j<=10-i;j++)
            {
                int num=0,dig=j,len=i;
                while(len--)
                {
                    num=num*10+dig;
                    dig++;
                }
                if(num>=low && num<=high)
                    ans.push_back(num);

            }
        }
        return ans;
    }
};