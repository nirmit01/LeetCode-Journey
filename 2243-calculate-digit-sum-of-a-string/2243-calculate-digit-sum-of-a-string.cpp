class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            int n=s.size();
            string temp;
            for(int i=0;i<n;i+=k)
            {
                int j=i;
                int x=0;
                while(j<n && j<i+k)
                {
                    x+=(s[j]-'0');
                    j++;
                }
                temp+=to_string(x);
            }
            s=temp;
        }
        return s;
    }
};