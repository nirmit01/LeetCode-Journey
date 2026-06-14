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
    int pairSum(ListNode* head) {
        ListNode* temp1=head, *temp2=head;
        while(temp2->next->next)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        ListNode* curr=temp1->next, *prev=nullptr;
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        temp1->next=prev;
        int ans=0;
        ListNode* head1=head, *head2=prev;
        while(head2)
        {
            ans=max(ans,head1->val+head2->val);
            head1=head1->next;
            head2=head2->next;
        }
        return ans;
    }
};