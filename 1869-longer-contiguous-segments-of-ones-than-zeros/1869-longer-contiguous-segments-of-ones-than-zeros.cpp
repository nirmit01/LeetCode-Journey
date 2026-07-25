class Solution {
public:
    bool checkZeroOnes(string s) {
        int max1=0,max2=0;
        int i=0,n=s.size();
        while(i<n)
        {
            int curr1=0, curr2=0;
            while(i<n && s[i]=='1')
            {
                curr1++;
                i++;
            }
            max1=max(max1,curr1);
            while(i<n && s[i]=='0')
            {
                curr2++;
                i++;
            }
            max2=max(max2,curr2);
        }   
        return max1>max2;
    }
};