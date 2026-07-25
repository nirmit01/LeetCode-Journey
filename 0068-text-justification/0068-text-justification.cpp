class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> ans;
        int i=0;
        while(i<n)
        {
            int len=words[i].size(),cnt=words[i].size();
            int j=i+1;
            while(j<n && (len+words[j].size()+1)<=maxWidth)
            {
                len+=words[j].size()+1;
                cnt+=words[j].size();
                j++;
            }
            int spaces=maxWidth-cnt;

            int slots=(j-i-1);
            string s="";
            if(slots==0)
            {
                s+=words[i++];
                s.append(spaces,' ');
            }
            else if(j==n)
            {
                s+=words[i++];
                while(i<j)
                {
                    s+=" ";
                    s+=words[i++];
                }
                while(s.size()<maxWidth)
                    s+=" ";
            }
            else
            {
                int base=spaces/slots;
                int extra=spaces%slots;
                while(i<j)
                {
                    s+=words[i];
                    if(i<j-1)
                    {
                        s.append(base,' ');
                        if(extra>0)
                        {
                            s+=" ";
                            extra--;
                        }
                    }
                    i++;
                }
            }
            ans.push_back(s);
        }
        return ans;   
    }
};