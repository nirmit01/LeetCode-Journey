class Solution {
public:
    int find(int x,vector<int>& parent)
    {
        if(parent[x]==x)
            return x;
        
        return parent[x]=find(parent[x],parent);
    }

    void unite(int x,int y,vector<int>& parent)
    {
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py)
            return;
        parent[px]=py; 
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i=0;i<26;i++)
            parent[i]=i;
        
        for(string& s:equations)
        {
            if(s[1]=='=')
                unite(s[0]-'a',s[3]-'a',parent);
        }
        for(string &s:equations)
        {
            if(s[1]=='!' && (find(s[0]-'a',parent)==(find(s[3]-'a',parent))))
                return false;
        }
        return true;
    }
};