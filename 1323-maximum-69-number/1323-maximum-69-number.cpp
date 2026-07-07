class Solution {
public:
    int maximum69Number (int num) {
        bool flag=true;
        string s=to_string(num);
        for(char& c:s)
        {
            if(c=='6')
            {
                c='9';
                break;
            }
        }
        return stoi(s);
    }
};