class Solution {
public:
    int largestInteger(int num) {
        int arr[10];
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'0']++;
        }
        int o=9,e=8;
        for(int i=0;i<s.size();i++)
        {
            int k=s[i]-'0';
            if(k%2==0)
            {
                while(arr[e]==0)
                    e-=2;
                arr[e]--;
                s[i]=e+'0';
            }
            else
            {
                while(arr[o]==0)
                    o-=2;
                arr[o]--;
                s[i]=o+'0';
            }
        }
        return stoi(s);
    }
};