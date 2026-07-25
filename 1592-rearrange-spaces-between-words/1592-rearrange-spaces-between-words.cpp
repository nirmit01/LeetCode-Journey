class Solution {
public:
    string reorderSpaces(string text) {
        string ans="";
        vector<string> vec;
        int i=0,n=text.size();
        int cnt=0;
        while(i<n)
        {
            while(i<n && text[i]==' ')
            {
                cnt++;
                i++;
            }
            string word="";
            while(i<n && text[i]!=' ')
            {
                word+=text[i];
                i++;
            }
            if(!word.empty())
                vec.push_back(word);
        }
        if(vec.size()==1)
        {
            ans+=vec[0];
            ans.append(cnt,' ');
        }
        else
        {
            int slots=vec.size()-1;
            int base= cnt/slots;
            int extra= cnt%slots;
            ans+=vec[0];
            for(int i=1;i<vec.size();i++)
            {
                ans.append(base,' ');
                ans+=vec[i];
            }
            ans.append(extra,' ');
        }
        return ans;
    }
};