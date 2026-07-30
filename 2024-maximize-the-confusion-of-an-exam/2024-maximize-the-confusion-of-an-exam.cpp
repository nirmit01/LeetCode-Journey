class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cnt1=0,cnt2=0,ans=0;
        int j=0,n=answerKey.size();
        for(int i=0;i<n;i++)
        {
            if(answerKey[i]=='T')   cnt1++;
            else    cnt2++;

            while(min(cnt1,cnt2)>k)
            {
                if(answerKey[j]=='T')   cnt1--;
                else    cnt2--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};