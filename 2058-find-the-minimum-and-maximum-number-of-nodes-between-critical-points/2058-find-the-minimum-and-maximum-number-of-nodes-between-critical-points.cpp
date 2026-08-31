/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int maxi=-1, mini=INT_MAX, j=-1,j2=-1;
        int i=1;
        while(head->next && head->next->next){
            ListNode* temp=head->next;
            if((temp->val > head->val && temp->val > temp->next->val) || 
            (temp->val < head->val && temp->val < temp->next->val)){
                if(j==-1){
                    j=i;
                    j2=i;
                }
                else{
                    maxi=max(maxi,i-j);
                    mini=min(mini,i-j2);
                    j2=i;
                }
            }
            i++;
            head=head->next;
        }
        if(mini==INT_MAX)
            mini=-1;
        return {mini,maxi};
    }
};