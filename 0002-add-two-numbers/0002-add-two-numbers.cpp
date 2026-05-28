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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* ans = sum;
        int c=0;
        while(l1!=NULL || l2!=NULL || c>0)
        {
            int a =(l1!=NULL ? l1->val : 0);
            int b =(l2!=NULL ? l2->val : 0);
            int x=a+b+c;
            int dig=x%10;
            c=x/10;
            sum->next= new ListNode(dig);
            sum=sum->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        return ans->next;
    }
};