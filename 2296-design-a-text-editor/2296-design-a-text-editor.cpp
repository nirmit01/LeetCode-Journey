class TextEditor {
public:
    string s;
    int idx;
    TextEditor() {
        s="";
        idx=0;
    }
    
    void addText(string text) {
        int n=text.size();
        s.insert(idx,text);
        idx+=n;
    }
    
    int deleteText(int k) {
        if(idx<k)
        {
            int temp=idx;
            s.erase(0,idx);
            idx=0;
            return temp;
        }
        idx-=k;
        s.erase(idx,k);
        return k;
    }
    
    string cursorLeft(int k) {
        if(idx<k)
        {
            idx=0;
            return "";
        }
        idx-=k;
        int temp=min(10,idx);
        return s.substr(idx-temp,temp);
    }
    
    string cursorRight(int k) {
        int n=s.size();
        if(idx>n-k)
        {
            idx=n;
        }
        else
        {
            idx+=k;
        }
        int temp=min(10,idx);
        return s.substr(idx-temp,temp);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */