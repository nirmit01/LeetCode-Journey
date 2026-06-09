class Solution {
public:
    int compress(vector<char>& chars) {
        int j=0,i=0,n=chars.size();
        while(i<n)
        {
            char c=chars[i];
            int cnt=0;
            while(i<n && chars[i]==c)
            {
                i++;
                cnt++;
            }
            if(cnt==1)
            {
                chars[j++]=c;
            }
            else
            {
                chars[j++]=c;
                string s=to_string(cnt);
                for(char k:s)
                {
                    chars[j++]=k;
                }
            }
        }
        return j;
    }
};