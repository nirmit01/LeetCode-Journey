class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i:arr1)
        {
            while(!st.count(i) && i>0)
            {
                st.insert(i);
                i/=10;
            }
        }
        int ans=0;
        for(int i:arr2)
        {
            while(!st.count(i) && i>0)
            {
                i/=10;
            }
            if(i>0)
                ans=max(ans,(int)log10(i)+1);
        }
        return ans;
    }
};