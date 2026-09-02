class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
            int k1=i%3, k2=i%5;
            if(k1==0 && k2==0)
                ans.push_back("FizzBuzz");
            else if(k1==0)
                ans.push_back("Fizz");
            else if(k2==0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }
};