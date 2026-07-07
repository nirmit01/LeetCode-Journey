class Solution {
public:
    int maximum69Number (int num) {
        int temp=num,pos=0,curr=1;
        while(temp>0)
        {
            int k=temp%10;
            temp/=10;
            if(k==6)
            {
                pos=curr;
            }
            curr*=10;
        }
        num+=3*pos;
        return num;
        // string s=to_string(num);
        // for(char& c:s)
        // {
        //     if(c=='6')
        //     {
        //         c='9';
        //         break;
        //     }
        // }
        // return stoi(s);
    }
};