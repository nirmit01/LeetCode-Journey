class Solution {
public:
    int minimizedStringLength(string s) {
        int arr[26];
        memset(arr,0,sizeof(arr));
        int ans=0;
        for(char c:s)
        {
            if(arr[c-'a']==0)
            {
                ans++;
                arr[c-'a']=1;
            }
        }
        return ans;
    }
};