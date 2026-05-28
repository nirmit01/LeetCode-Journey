class Solution {
public:
    bool isPalindrome(int x) {
        // if(x<0 || x%10==0 && x!=0)
        //     return false;
        // int rev=0;
        // while(x>rev)
        // {
        //     rev=rev*10+x%10;
        //     x/=10;
        // }
        // return(x==rev || x==rev/10);
        string s=to_string(x);
        string k=s;
        reverse(s.begin(),s.end());
        return(k==s);
    }
};